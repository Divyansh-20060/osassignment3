#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/cred.h>
#include<linux/types.h>
#include<linux/highuid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Divyansh");
MODULE_DESCRIPTION("New module that prints proccesses information corresponding to a pid\n");

int ProId = 0;
module_param(ProId, int, 0);

static int __init pro_info(void){ //change name to whatever
	printk("pid: %d", pid_task(find_vpid(ProId), PIDTYPE_PID)->pid );
	printk("user id: %d", (int)pid_task(find_vpid(ProId), PIDTYPE_PID)->real_cred->uid.val );
	printk("pgid: %d", pid_task(find_vpid(ProId), PIDTYPE_PID)->real_cred->gid.val );
	printk("command path: %s", pid_task(find_vpid(ProId), PIDTYPE_PID)->comm );
	return 0;
}

static void __exit pro_exit(void){
	printk("Terminating succesfully\n");
}
module_init(pro_info);
module_exit(pro_exit);