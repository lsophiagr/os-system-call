#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/syscall.h>
#include <string.h>
int main(void){
	
    char st[256];
    printf("Enter the : ");
    fgets(st, sizeof(st), stdin);  // read string
    printf("Name: ");
    puts(st);

    long sta = syscall(337, st, 20);
    //I type 20 simply because I don't want to do any math
    printf("return value from syscall: %ld\n", sta);
    return 0;
}