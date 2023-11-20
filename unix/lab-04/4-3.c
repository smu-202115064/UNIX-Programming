#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    pid_t pid;
    char *a[3];

    if((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        printf("Parent %d executes.\n", (int)getpid());
    }
    else {
        printf("Child %d executes.\n", (int)getpid());
        a[0] = "ls";
        a[1] = "-a";
        a[2] = NULL; // execv() 계열의 함수로 인자를 전달 할 때, 인자 배열의 마지막 원소는 NULL 이어야 한다.
        if (execv("/bin/ls", a) == -1) {
            perror("exec");
            exit(2);
        }
    }

    return 0;
}
