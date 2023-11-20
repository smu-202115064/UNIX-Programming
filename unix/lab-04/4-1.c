#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    pid_t pid;

    printf("Before fork ...\n");

    if ((pid = fork()) < 0) {
        // Fork 실패 시, pid는 -1 이 반환되므로 이 블록 구문으로 진입한다.
        perror("fork"); // "fork" 문자열과 함께 에러 메시지를 출력한다.
        exit(1);
    }
    if (pid > 0) {
        // pid가 0이 아닌 양수이면 부모 프로세스라는 뜻이다.
        // 따라서, 부모 프로세스는 이 블록 구문으로 진입한다.
        sleep(2);
        printf("Parent process has pid = %d ppid = %d\n", (int)getpid(), (int)getppid());
    }
    else
        // pid가 0이라는 것은 자식 프로세스라는 뜻이다.
        // 따라서, 자식 프로세스는 이 블록 구문으로 진입한다.
        printf("Child process has pid = %d ppid = %d\n", (int)getpid(), (int)getppid());

    printf("End of fork ...\n");

    return 0;
}
