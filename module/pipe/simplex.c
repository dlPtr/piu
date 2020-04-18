#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "log/log.h"
#include "misc.h"

int simplex_com(int argc, char *argv[])
{
    int ret = 0;
    int fd[2] = {0};
    char buff[MAX_BUFFER_LENGTH] = {0};

    /* Create pipe, fd[0] for read and fd[1] for write */
    ret = pipe(fd);
    assert(ret != -1);

    /* fork a process */
    ret = fork();
    assert(ret != -1);
    if (0 == ret) {
        close(fd[1]);

        /* child process, read from pipe */
        read(fd[0], SLEN(buff));
        ut_log_info("I am child process, read something(%s) from father", buff);

        close(fd[0]);
    } else {
        close(fd[0]);

        /* parent process, write and then wait */
        write(fd[1], SLEN("Hello, Micky!"));
        
        /* wait child to exit */
        wait(NULL);

        ut_log_info("Parent process quit!");
        close(fd[1]);
    }

    return 0;
}