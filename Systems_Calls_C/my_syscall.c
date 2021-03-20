#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>

SYSCALL_DEFINE0(my_syscall_0)
{
    printk("my_syscall_0\n");
    return 0;
}

SYSCALL_DEFINE0(hellow)
{
   printk("Hello world \n");
   return 0;
}

SYSCALL_DEFINE1(my_syscall_1, int, a)
{
    printk("my_syscall_1 : %d\n", a);
    return 0;
}

SYSCALL_DEFINE2(printstring, char __user *, src, int, len)
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

SYSCALL_DEFINE2(checkstring, char __user *, src, int, len)
{
    char buf[256];
    unsigned long lenleft = len;
    unsigned long chunklen = sizeof(buf);
    int i;
    int countP = 0;
    int countC = 0;

    while( lenleft > 0 ){
            if( lenleft < chunklen ) chunklen = lenleft;
            if( copy_from_user(buf, src, chunklen) ){
                return -EFAULT;
            }
            lenleft -= chunklen;
    }

    printk("Texto copiado en el kernel %s\n", buf);
    for (i = 0; i < 256; ++i)
    {
        if (*(buf+i) == '(') {
        countP = countP + 1;
        }
        
        if (*(buf+i) == ')') {
        countP = countP - 1;
        }
        
        if (*(buf+i) == '[') {
        countC = countC + 1;
        }
        
        if (*(buf+i) == ']') {
        countC = countC - 1;
        }
    }

    if ((countP != 0) || (countC != 0)){
        printk("No esta balance\n");
        return 0;
        
    }  else {
        printk("Esta balance\n");
        return 1;
    }
}