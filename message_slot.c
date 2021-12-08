// Declare what kind of code we want
// from the header files. Defining __KERNEL__
// and MODULE allows us to access kernel-level
// code not usually available to userspace programs.
#undef __KERNEL__
#define __KERNEL__
#undef MODULE
#define MODULE

#include "message_slot.h"


#include <sys/types.h>
#include <stddef.h>

MODULE_LICENSE("GPL");

// The message the device will give when asked
static char the_message[BUF_LEN];

// device major number
static int major = MAJOR_NUM;



//================== DEVICE FUNCTIONS ===========================
static int device_open( struct inode* inode,
                        struct file*  file )
{
    //to be done
}

//---------------------------------------------------------------
static int device_release( struct inode* inode,
                           struct file*  file)
{
    //to be done
}

//---------------------------------------------------------------
// a process which has already opened
// the device file attempts to read from it
static ssize_t device_read( struct file* file, char __user* buffer, size_t length, loff_t* offset )
    {
    // read doesnt really do anything (for now)
    printk( "Invocing device_read(%p,%ld) - " "operation not supported yet\n" "(last written - %s)\n",
        file, length, the_message );

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
    // Switch according to the ioctl called
    if( IOCTL_SET_CHANNEL == ioctl_command_id )
    {
        // Get the parameter given to ioctl by the process
        printk( "Invoking ioctl: setting channel to %d\n", ioctl_param );
        file->private_data = ioctl_param;
    }

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
static int __init simple_init(void)
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
    // Unregister the device
    // Should always succeed
    unregister_chrdev(major, DEVICE_RANGE_NAME);
}

//---------------------------------------------------------------
module_init(simple_init);
module_exit(simple_cleanup);
//========================= END OF FILE =========================
