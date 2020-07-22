#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "../demo_fifo.h"
#include "log/log.h"


int run_client1(int argc, char *argv[])
{
    int ret = 0;
    int fd = -1;
    char buf[MAX_BUFFER_LENGTH] = {0};

    /* Create fifo */
    ret = mkfifo(FIFO_SIMPLEX_PATH, 0664);
    assert(!ret || errno == EEXIST);

    /* open fifo */
    fd = open(FIFO_SIMPLEX_PATH, O_RDONLY);
    assert(fd != -1);

    read(fd, SLEN(buf));
    ut_log_info("Get timestamp from fifo: %s", buf);

    close(fd);
    return 0;
}