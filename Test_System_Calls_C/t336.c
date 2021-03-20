#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/syscall.h>
#include <string.h>
int main(void){

    char st[256];
    sprintf(st, "hello kernel!");
    
    long sta = syscall(336, st, 20);
    //I type 20 simply because I don't want to do any math
    printf("return value from syscall: %ld\n", sta);
    return 0;
}