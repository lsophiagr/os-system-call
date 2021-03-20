#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
int main()
{
    printf("1 : %d\n", syscall(333));
    return 0;
}

