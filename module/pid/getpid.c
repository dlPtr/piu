#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "log/log.h"

int main(int argc, char *argv[])
{
    pid_t myPid = getpid();

    ut_log_info("pid of mine is %d\n", myPid);
    ut_log_info("And my father's pid is %d\n", getppid());

    return 0;
}
