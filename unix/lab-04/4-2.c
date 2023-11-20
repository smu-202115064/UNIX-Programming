#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    pid_t pid;

    for (int i = 0; i < 3; i++) {
        pid = fork();

        if (pid < 0) {
            // Fork 에 실패하면 에러메시지 출력 후 프로세스 종료.
            perror("fork");
            exit(1);
        }

        if (pid == 0) {
            // 현재 프로세스가 부모 프로세스가 아니라면,
            // 문제의 요구사항대로 자신의 pid와 parent pid를 출력한 뒤,
            // 더 이상 Fork를 진행 하지 않도록 for-loop를 탈출한다.
            printf("my pid is %d and ppid is %d\n", (int)getpid(), (int)getppid());
            break;
        }
    }

    return 0;
}
