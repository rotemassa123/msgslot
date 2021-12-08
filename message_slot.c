// Declare what kind of code we want
// from the header files. Defining __KERNEL__
// and MODULE allows us to access kernel-level
// code not usually available to userspace programs.
#undef __KERNEL__
#define __KERNEL__
#undef MODULE
#define MODULE

#include "message_slot.h"

#include <linux/kernel.h>   /* We're doing kernel work */
#include <linux/module.h>   /* Specifically, a module */
#include <linux/fs.h>       /* for register_chrdev */
#include <linux/uaccess.h>  /* for get_user and put_user */
#include <linux/string.h>   /* for memset. NOTE - not string.h!*/
#include <linux/radix-tree.h>

#include <sys/types.h>
#include <stddef.h>

MODULE_LICENSE("GPL");

// device major number
static int major = MAJOR_NUM;

//all message slots
static struct radix_tree_root * message_slots[256];


//================== DEVICE FUNCTIONS ===========================
static int device_open( struct inode* inode,
                        struct file*  file )
{
    unsigned int minor = iminor(inode);
    //file->f_inode = inode;
    if (message_slots[minor] != NULL) { return SUCCESS; }

    INIT_RADIX_TREE(message_slots[minor], gfp_allowed_mask);
}

//---------------------------------------------------------------
static int device_release( struct inode* inode, struct file*  file)
{

}

//---------------------------------------------------------------
// a process which has already opened
// the device file attempts to read from it
static ssize_t device_read( struct file* file, char __user* buffer, size_t length )
    {
    unsigned int minor = iminor(file->f_inode);

    //invalid argument error
    return -EINVAL;
}

//---------------------------------------------------------------
// a processs which has already opened
// the device file attempts to write to it
static ssize_t device_write( struct file* file, const char __user* buffer, unsigned long channel, int length, loff_t* offset)
{
    int i;
    printk("Invoking device_write(%p,%ld)\n", file, length);
    for( i = 0; i < length && i < BUF_LEN; ++i )
    {
    get_user(the_message[i], &buffer[i]);
}

// return the number of input characters used
return i;
}

static long device_ioctl( struct   file* file,
                          unsigned int   ioctl_command_id,
                          unsigned long  ioctl_param )
{
    file->private_data = IOCTL_SET_CHANNEL == ioctl_command_id ? &ioctl_param : NULL;
    return SUCCESS;
}

//==================== DEVICE SETUP =============================

// This structure will hold the functions to be called
// when a process does something to the device we created
struct file_operations Fops =
        {
                .owner	        = THIS_MODULE, // Required for correct count of module usage. This prevents the module from being removed while used.
                .read           = device_read,
                .write          = device_write,
                .open           = device_open,
                .unlocked_ioctl = device_ioctl,
                .release        = device_release,

        };

//---------------------------------------------------------------
// Initialize the module - Register the character device
static int __init _init(void)
{

    // init dev struct
    memset( &device_info, 0, sizeof(struct chardev_info) );
    spin_lock_init( &device_info.lock );

    // Register driver capabilities. Obtain major num
    major = register_chrdev( 0, DEVICE_RANGE_NAME, &Fops );

    // Negative values signify an error
    if( major < 0 )
    {
        printk( KERN_ALERT "%s registraion failed for  %d\n",
                DEVICE_FILE_NAME, major );
        return major;
    }

    printk( "Registeration is successful. "
            "The major device number is %d.\n", major );
    printk( "If you want to talk to the device driver,\n" );
    printk( "you have to create a device file:\n" );
    printk( "mknod /dev/%s c %d 0\n", DEVICE_FILE_NAME, major );
    printk( "You can echo/cat to/from the device file.\n" );
    printk( "Dont forget to rm the device file and "
            "rmmod when you're done\n" );

    return 0;
}

//---------------------------------------------------------------
static void __exit simple_cleanup(void)
{
    //free all memory
    int i;
    void** slot;
    struct radix_tree_iter *iter;

    for(i = 0; i < 256; i++){
        radix_tree_for_each_slot(slot, message_slots[i], iter, 0){
            kf
        }

    }
    unregister_chrdev(major, DEVICE_RANGE_NAME);
}

//---------------------------------------------------------------
module_init(simple_init);
module_exit(simple_cleanup);
//========================= END OF FILE =========================
