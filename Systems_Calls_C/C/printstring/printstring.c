#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
/* function to print string to kernel */
SYSCALL_DEFINE2(printstring,
		char __user *, src,
		int, len)
{
        char buf[256];
        unsigned long lenleft = len;
        unsigned long chunklen = sizeof(buf);
        while( lenleft > 0 ){
                if( lenleft < chunklen ) chunklen = lenleft;
                if( copy_from_user(buf, src, chunklen) ){
    		        return -EFAULT;
    	        }
                lenleft -= chunklen;
        }
    
        printk("Texto copiado %s\n", buf);
    
        return 0;
}