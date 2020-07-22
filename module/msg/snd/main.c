#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#include "log/log.h"

#define MSG_KEY             1024
#define MSG_DATA_LENGTH     2048

typedef struct msg_stru {
    long msg_type;
    char msg_data[MSG_DATA_LENGTH];
}msg_stru, *p_msg_stru;

int main(int argc, char *argv[])
{
    msg_stru one_msg;
    int msg_id;
    int type;
    char buff[MSG_DATA_LENGTH] = {0};

    msg_id = msgget(MSG_KEY, IPC_CREAT | 0666);
    if (msg_id < 0) {
        ut_log_error("msgget failed\n");
        return -1;
    }

    while (1) {
        printf("[msg type]>>");
        scanf("%d", &type);
        if (type == 0) {
            ut_log_error("don't input 0 as msg type!");
            break;
        }

        printf("[msg data]>>");
        scanf("%s", buff);
        one_msg.msg_type = type;
        snprintf(one_msg.msg_data, MSG_DATA_LENGTH, "%s", buff);

        if (0 > msgsnd(msg_id, &one_msg, sizeof(msg_stru), IPC_NOWAIT)) {
            ut_log_error("msgsnd failed!");
            return -1;
        }
    }
    

    msgctl(msg_id, IPC_RMID, 0);

    return 0;
}