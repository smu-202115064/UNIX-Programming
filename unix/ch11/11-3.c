#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    key_t key;
    int msgid;

    key = ftok("keyfile", 1);
    msgid = msgget(key, IPC_CREAT|0644); // 큐가 없었어도 여기서 만들어졌을 것.
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Before IPC_RMID\n");
    system("ipcs -q");
    msgctl(msgid, IPC_RMID, (struct msqid_ds *)NULL); // NULL을 주는 이유는 해당 파라미터를 사용하지 않겠다는 의미.
    printf("After IPC_RMID\n");
    system("ipcs -q");
}