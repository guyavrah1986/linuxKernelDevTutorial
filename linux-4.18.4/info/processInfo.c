#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>

#include "processInfo.h"

asmlinkage long sys_getProcessInfo(char __user *buff, size_t buffsz)
{
	// get the executable name of the current (invoking) process
	if (buff == NULL)
	{
		printk("getProcessInfo - got NULL pointer as buffer (from user space)");
		return -EFAULT;		
	}

	printk("getProcessInfo - current process comm filed is: %s \n",  proces->comm);
	return 0;
}
