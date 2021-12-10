#ifndef CHARDEV_H
#define CHARDEV_H

#include <linux/ioctl.h>
#include <linux/radix-tree.h>

#define MAJOR_NUM 240

// Set the message of the device driver

#define DEVICE_RANGE_NAME "message_slot"
#define SUCCESS 0
#define IOCTL_SET_CHANNEL 8

typedef struct {
    char * msg;
    unsigned long length;
    unsigned long number;
}Channel;

#endif
