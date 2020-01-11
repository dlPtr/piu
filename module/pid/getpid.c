#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "log/log.h"

int main(int argc, char *argv[])
{
    pid_t myPid = getpid();

    printf("pid of mine is %d\n", myPid);
    printf("And my father's pid is %d\n", getppid());

    return 0;
}
