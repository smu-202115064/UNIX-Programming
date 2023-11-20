#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(void) {
    pid_t pid;
    struct stat statbuf;
    char buf[10];
    int fd, n, status;


    if((pid = fork()) < 0) {
        // fork에 실패하면 에러메시지 출력.
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        // 부모 프로세스는 4-5.txt를 읽어 stdout으로 출력.

        // 자식 프로세스가 종료되길 기다린다.
        wait(&status);

        //4-5.txt를 읽기모드로 연다.
        if ((fd = open("4-5.txt", O_RDONLY)) == -1) {
            perror("Open");
            exit(1);
        }

        //4-5.txt의 파일 크기를 알기위해 stat()을 사용한다.
        if (fstat(fd, &statbuf) == -1) {
            perror("stat");
            exit(2);
        }

        // 8글자씩 읽어와 stdout에 출력한다.
        // (버퍼는 크기가 10이기에 여유있다.)
        // stdout의 file descriptor는 1번이므로, 곧바로 stdout에다가 출력한다.
        while ((n = read(fd, buf, 8)) > 0)
        {
            // 4-5.txt에 쓰는 과정에서 오류가 발생하면 에러메시지 출력.
            if (write(1, buf, n) != n)
                perror("Write");
        }
        if (n == -1)
            // 읽는 과정에서 문제가 생기면 에러메시지 출력
            perror("Read");

        // 4-5.txt에서 읽어온 내용을 stdout에 쓰기가 완료되면 프로세스를 종료한다.
    }
    else {
        //4-5.txt를 쓰기모드로 연다.
        if ((fd = open("4-5.txt", O_CREAT | O_WRONLY | O_TRUNC)) == -1) {
            perror("Open");
            exit(1);
        }

        // 8글자씩 읽어와서 쓰기모드로 연 4-5.txt에 출력한다.
        // (버퍼는 크기가 10이기에 여유있다.)
        // stdin의 file descriptor는 0번이므로, 곧바로 stdin에서 읽어온다.
        while ((n = read(0, buf, 8)) > 0)
        {
            // 4-5.txt에 쓰는 과정에서 오류가 발생하면 에러메시지 출력.
            if (write(fd, buf, n) != n)
                perror("Write");
        }
        if (n == -1)
            perror("Read");

        // stdin에서 읽어온 내용을 4-5.txt에 쓰기가 완료되면 프로세스를 종료한다.
    }

    return 0;
}
