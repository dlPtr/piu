#ifndef _DEMO_FIFO_H
#define _DEMO_FIFO_H

#define MODULE_PATH "/home/ubuntu/workspace/dev/piu/module/"

#define FIFO_SIMPLEX_PATH MODULE_PATH"fifo/simplex.fifo"
#define FIFO_DUMPLEX_PATH MODULE_PATH"fifo/dumplex.fifo"

#define MAX_BUFFER_LENGTH (1024)

#define SLEN(x) x, sizeof(x)

int simplex_com(int argc, char *argv[]);
int duplex_com(int argc, char *argv[]);

int run_client1(int argc, char *argv[]);

#endif /* _DEMO_FIFO_H */