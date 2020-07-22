#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/stat.h>


#include "../demo_fifo.h"
#include "log/log.h"

int g_fd = -1;

void signal_handler(int sig)
{
    switch (sig)
    {
    case SIGINT:
        close(g_fd);
        assert(!unlink(FIFO_SIMPLEX_PATH));
        ut_log_info("quit");
        break;
    
    default:
        ut_log_info("Caught signo %d", sig);
        break;
    }
}

int simplex_com(int argc, char *argv[])
{
    int ret = 0;
    char buf[MAX_BUFFER_LENGTH] = {0};
    time_t ts = 0;

    /* Create fifo */
    ret = mkfifo(FIFO_SIMPLEX_PATH, 0664);
    assert(!ret);

    /* open fifo */
    g_fd = open(FIFO_SIMPLEX_PATH, O_WRONLY);
    assert(g_fd != -1);

    /* set signal */
    signal(SIGINT, signal_handler);

    while (1) {
        ts = time(NULL);
        snprintf(SLEN(buf), "%ld", ts);
        write(g_fd, SLEN(buf));
        
    }

    return 0;
}