#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "log/log.h"
#include "misc.h"

int duplex_com(int argc, char *argv[])
{
    int ret = 0;
    int fd1[2] = {0};
    int fd2[2] = {0};
    char buff1[MAX_BUFFER_LENGTH] = {0};
    char buff2[MAX_BUFFER_LENGTH] = {0};

    /* Create pipe, fd[0] for read and fd[1] for write */
    ret = pipe(fd1);
    assert(ret != -1);
    ret = pipe(fd2);
    assert(ret != -1);

    /* fork a process */
    ret = fork();
    assert(ret != -1);
    if (0 == ret) {
        close(fd1[1]);
        close(fd2[0]);

        /* child process, read from pipe */
        read(fd1[0], SLEN(buff1));

        /* after read, write something to parent */
        write(fd2[1], SLEN("hello, motherfucker"));

        ut_log_info("I am child process, read something(%s) from father", buff1);

        close(fd1[0]);
        close(fd2[1]);
    } else {
        close(fd1[0]);
        close(fd2[1]);

        /* parent process, write */
        write(fd1[1], SLEN("Hello, Micky!"));

        /* wait child to exit */
        wait(NULL);

        /* after write, wait for child's response */
        read(fd2[0], SLEN(buff2));
        ut_log_info("Reseive something(%s) from child", buff2);

        close(fd1[1]);
        close(fd2[0]);
    }

    return 0;
}