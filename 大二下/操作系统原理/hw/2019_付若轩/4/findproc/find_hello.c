#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>

/* This function is called when the module is loaded. */
int pl_entry(void)
{
       struct task_struct *curr;
       for_each_process(curr)
       {
       	if(curr->pid == 9616)
       	{
			printk(KERN_INFO "I found the pcb of hello world!\n");
			break;
		}
       }

       return 0;
}

/* This function is called when the module is removed. */
void pl_exit(void) {
	printk(KERN_INFO "Exit!\n");
}

/* Macros for registering module entry and exit points. */
module_init(pl_entry);
module_exit(pl_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("list processes");
MODULE_AUTHOR("zhaohj");

/* ps -el | wc -l */

