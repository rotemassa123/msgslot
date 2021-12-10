// Declare what kind of code we want
// from the header files. Defining __KERNEL__
// and MODULE allows us to access kernel-level
// code not usually available to userspace programs.
#undef __KERNEL__
#define __KERNEL__
#undef MODULE
#define MODULE

#include "message_slot.h"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include <linux/radix-tree.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <stddef.h>



MODULE_LICENSE("GPL");

// device major number
static int major = MAJOR_NUM;

//all message slots
static struct radix_tree_root * message_slots[256];

//================== DEVICE FUNCTIONS ===========================
static int device_open( struct inode* inode, struct file*  file )
{
    unsigned int minor;
    printk("devce_open is called...");

    minor = iminor(inode);
    if (message_slots[minor] != NULL) { return SUCCESS; }

    if((message_slots[minor] = kmalloc(sizeof(struct radix_tree_root *), GFP_KERNEL)) == NULL) { return -ENOMEM; }
    INIT_RADIX_TREE(message_slots[minor], GFP_KERNEL);

    printk("device open success!");

    return SUCCESS;
}

//---------------------------------------------------------------
static int device_release( struct inode* inode, struct file*  file)
{
    //Channel * channel;
    //channel = (Channel *)file->private_data;
    //kfree(channel);
    return SUCCESS;
}

//---------------------------------------------------------------
// a process which has already opened
// the device file attempts to read from it
static ssize_t device_read(struct file *file, char __user* buffer, size_t length, loff_t *offset)
    {
    unsigned int minor;
    Channel *channel;
    unsigned long channel_number;
    int i;

    printk("device_read is called...");


    minor = iminor(file->f_inode);
    if(file->private_data == NULL) { return -EINVAL; }
    channel_number = (unsigned int) (unsigned long) file->private_data;
    if((channel = radix_tree_lookup(message_slots[minor], channel_number)) == NULL) { return -EWOULDBLOCK; }

    if(channel->length > length) { return -ENOSPC; }
    printk("device_read: channel->msg is: %s", channel->msg);

    if(channel->msg == NULL) { return -EWOULDBLOCK; }

    for( i = 0; i < channel->length ; i++ )
        if((put_user(channel->msg[i], &buffer[i])) != 0)
            return -EFAULT;


    return channel->length;
}

//---------------------------------------------------------------
// a processs which has already opened
// the device file attempts to write to it
static ssize_t device_write(struct file *file, const char __user* buffer, size_t length, loff_t * offset)
{
    Channel *channel;
    unsigned int minor;
    int i;

    printk("device_write is called...");

    channel = kmalloc(sizeof(Channel), GFP_KERNEL);

    if(length == 0 || length > 128) { return -EMSGSIZE; }
    channel->length = length;

    if(file->private_data == NULL) { return -EINVAL; }
    if((channel->number = (unsigned int) (unsigned long) file->private_data) == 0) { return -EINVAL; }


    minor = iminor(file->f_inode);
    if(radix_tree_lookup(message_slots[minor], channel->number) != NULL) { radix_tree_delete(message_slots[minor], channel->number); }
    if((channel->msg = kcalloc(length, sizeof(char), GFP_KERNEL)) == NULL) { return -ENOMEM; }


    for( i = 0; i < length ; ++i )
        if((get_user(channel->msg[i], &buffer[i])) != 0)
            return -EFAULT;

    printk("message is: %s", channel->msg);

    radix_tree_insert(message_slots[minor], channel->number, channel);

    printk("%s was inserted to minor %d on channel %lu", ((Channel *) radix_tree_lookup(message_slots[minor], channel->number))->msg, minor, channel->number);

    printk("device write success!");

    return channel->length;
}


static long device_ioctl( struct   file* file,
                          unsigned int   ioctl_command_id,
                          unsigned long  ioctl_param )
{
    printk("device_ioctl is called...");
    if(ioctl_command_id != MSG_SLOT_CHANNEL) { return -EINVAL; }
    file->private_data = (void *) (unsigned long) ioctl_param;

    printk("device ioctl success!");
    return SUCCESS;
}

//==================== DEVICE SETUP =============================

// This structure will hold the functions to be called
// when a process does something to the device we created
struct file_operations Fops =
        {
                .owner          = THIS_MODULE,
                .read           = device_read,
                .write          = device_write,
                .open           = device_open,
                .unlocked_ioctl = device_ioctl,
                .release        = device_release,
        };

//---------------------------------------------------------------
// Initialize the module - Register the character device
static int __init _init_module(void)
{
    int err;

    printk("__init_module: registering chrdev");
    // Register driver capabilities. Obtain major num
    err = register_chrdev( major, DEVICE_RANGE_NAME, &Fops );
    printk("__init_module: finished registering chrdev");

    // Negative values signify an error
    if( err < 0 )
    {
        printk( KERN_ALERT "%s registraion failed for  %d\n",
                DEVICE_RANGE_NAME, err );
        return err;
    }
    return SUCCESS;
}

//---------------------------------------------------------------
static void __exit _exit_module(void)
{
    //free all memory
    int i;
    void** slot;
    struct radix_tree_iter iter;
    Channel *channel;

    unregister_chrdev(major, DEVICE_RANGE_NAME);

    for(i = 0; i < 256; i++){
        if(message_slots[i] != NULL){
            radix_tree_for_each_slot(slot, message_slots[i], &iter, 0){
                channel = radix_tree_deref_slot(slot);
                kfree(channel->msg);
                radix_tree_delete(message_slots[i], channel->number);
            }
            kfree(message_slots[i]);
        }
    }

}

//---------------------------------------------------------------
module_init(_init_module);
module_exit(_exit_module);
//========================= END OF FILE =========================