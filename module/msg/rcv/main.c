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

/**
 * @brief 获取消息队列中的数据并且打印出来
 */
void test_msg_rcv();

int main(int argc, char *argv[])
{
    test_msg_rcv();

    return 0;
}

void test_msg_rcv()
{
    msg_stru one_msg;
    int msg_id;
    int type;
    char buff[MSG_DATA_LENGTH] = {0};

    while (1) {
        msg_id = msgget(MSG_KEY, IPC_EXCL);
        if (msg_id < 0) {
            ut_log_error("msgget failed\n");
            return;
        }
        
        msgrcv(msg_id, &one_msg, sizeof(msg_stru), 0, 0);
        ut_log_info("[msg data]:<%s>", one_msg.msg_data);
    }

    return;
}