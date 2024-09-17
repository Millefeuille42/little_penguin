// SPDX-License-Identifier: GPL-3.0-or-later

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello world !\n");
	return 0;
}

void __exit hello_exit(void)
{
	printk(KERN_INFO "Cleaning up module\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL-3.0-or-later");
MODULE_AUTHOR("Millefeuille");
MODULE_DESCRIPTION("Logs \"hello world\"");
