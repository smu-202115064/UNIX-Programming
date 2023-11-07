#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int status;
    pid_t pid;
    pid_t cpid;

    // 4개의 자식 프로세스 생성
    for (int i = 0; i < 4; i++) {
        pid = fork();
        if (pid <= 0) {
            sleep(3);
            exit(2);
        }
    }

    printf("--> Parent Process\n");
    printf("Pid to wait for is %d.\n", pid);

    switch (pid) {
        case -1 : /* fork failed */
            perror("fork");
            exit(1);
            break;
        case 0 : /* child process */
            printf("--> Child Process\n");
            sleep(3);
            exit(2);
            break;
        default : /* parent process */
            while ((cpid = wait(&status)) != pid) {
                printf("Parent still wait for %d...\n", cpid);
                sleep(1);
                continue;
            }
            printf("--> Parent process\n");
            printf("Status: %d, %x\n", status, status);
            printf("Child process Exit Status:%d\n", status >> 8); // 1 Byte right-shift
            break;
    }
}