#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#include "processInfo.h"

asmlinkage long sys_getProcessInfo(const char __user* src, char __user** dst, long len)
{
	printk("getProcessInfo - got %ld bytes \n", len);
	char buff [256];
	/* copy src, which is in the user’s address space, into buf */
	if (copy_from_user(&buff, src, len))
		return -EFAULT;

	printk("getProcessInfo - got the string:%s \n", buff);

	*dst = (char*)kmalloc(sizeof(char) * len, GFP_USER);
	/* copy src, which is in the user’s address space, into buf */
	//if (copy_from_user(&buf, src, len))
	//	return -EFAULT;

	/* copy buf into dst, which is in the user’s address space */
	if (copy_to_user(src, *dst, len))
		return -EFAULT;

	/* return amount of data copied */
	return len;
}
