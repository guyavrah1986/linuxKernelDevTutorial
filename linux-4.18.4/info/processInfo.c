#include<linux/kernel.h>

#include "processInfo.h"

asmlinkage long sys_getProcessInfo(void)
{
	printk("getProcessInfo - hey there \n");
	return 0;
}
