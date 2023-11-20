#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>


#define FILE_NAME "4-6.txt"

// #define LOGGING_FN printf
#define LOGGING_FN do_nothing


void do_nothing(char *msg) {
    // 로깅용 함수.
    // 로깅을 하지 않을 때, 매크로 상수 LOGGING_FN 에 지정하기 위해 만들었다.
    return;
}


void parent_proc(pid_t child_pid) {
    char buf[10];
    int wfd;
    int n;

    LOGGING_FN("[Parent] 프로세스 진입.\n");

    sleep(1);`

    //4-6.txt를 쓰기모드로 연다.
    LOGGING_FN("[Parent] 4-6.txt 생성 시작.\n");
    if ((wfd = open(FILE_NAME, O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1) {
        perror("[Parent] Open");
        exit(1~);
    }

    // 8글자씩 읽어와서 쓰기모드로 연 4-6.txt에 출력한다.
    // (버퍼는 크기가 10이기에 여유있다.)
    // stdin의 file descriptor는 0번이므로, 곧바로 stdin에서 읽어온다.
    LOGGING_FN("[Parent] 4-6.txt에 내용 작성 시작.\n");
    while ((n = read(0, buf, 8)) > 0)
    {
        // 4-6.txt에 쓰는 과정에서 오류가 발생하면 에러메시지 출력.
        if (write(wfd, buf, n) != n)
            perror("[Parent] Write");
    }
    if (n == -1)
        perror("[Parent] Read");

    // stdin에서 읽어온 내용을 4-6.txt에 쓰기가 완료되면 파일을 닫는다.
    close(wfd);
    LOGGING_FN("[Parent] 4-6.txt 닫기 완료.\n");

    // 자식 노드가 작업을 이어 갈 수 있도록 "사용자 정의 시그널1"(10)을 전송한다.
    LOGGING_FN("[Parent] SIGUSR1(10) 시그널 전송.\n");
    kill(child_pid, SIGUSR1);

    LOGGING_FN("[Parent] 프로세스 종료.\n");

    // 부모 프로세스가 죽으면 bash의 다음 명령 입력을 기다리면서
    // "사용자명@호스트:현재경로"가 출력되는데, 이를 방지하기 위해 조금의
    // 대기시간을 걸었다 (실행결과 확인용.)
    sleep(5);

    exit(2);
}


void child_sig_handler(int signo) {
    char buf[10];
    int rfd;
    int n;
    struct stat statbuf;

    LOGGING_FN("[Child] 시그널 핸들러 진입.\n");

    //4-6.txt를 읽기모드로 연다.
    LOGGING_FN("[Child] 4-6.txt 읽기 시작.\n");
    if ((rfd = open(FILE_NAME, O_RDONLY)) == -1) {
        perror("[Child] Open");
        exit(1);
    }

    //4-6.txt의 파일 크기를 알기위해 stat()을 사용한다.
    if (fstat(rfd, &statbuf) == -1) {
        perror("[Child] Stat");
        exit(2);
    }

    // 8글자씩 읽어와 stdout에 출력한다.
    // (버퍼는 크기가 10이기에 여유있다.)
    // stdout의 file descriptor는 1번이므로, 곧바로 stdout에다가 출력한다.
    LOGGING_FN("[Child] 4-6.txt 내용을 stdout에 출력.\n");
    while ((n = read(rfd, buf, 8)) > 0)
    {
        // 4-6.txt에 쓰는 과정에서 오류가 발생하면 에러메시지 출력.
        if (write(1, buf, n) != n)
            perror("[Child] Write");
    }
    if (n == -1)
        // 읽는 과정에서 문제가 생기면 에러메시지 출력
        perror("[Child] Read");

    // 4-6.txt에서 읽어온 내용을 stdout에 쓰기가 완료되면
    // 파일을 닫고 프로세스를 종료한다.
    LOGGING_FN("[Child] 4-6.txt을 닫기.\n");
    close(rfd);
    exit(3);
}


void child_proc() {
    // 부모 프로세스가 종료되길 기다린다.
    //
    // 부모 프로세스는 종료되기 직전에 "사용자 정의 시그널1"(10)을 전송하도록
    // parent_proc()에 정의되어 있음을 이용한다.
    //
    // 부모 프로세스가 시그널을 전송하는 것을 기다리기 위해 pause()를 사용한다.
    LOGGING_FN("[Child] 프로세스 진입.\n");

    signal(SIGUSR1, child_sig_handler);
    sleep(3);

    pause();

    LOGGING_FN("[Child] 프로세스 종료.\n");
}


int main(void) {
    pid_t pid;

    if((pid = fork()) < 0) {
        // fork에 실패하면 에러메시지 출력.
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        // 부모 프로세스
        parent_proc(pid);
    } else {
        // 자식 프로세스
        child_proc();
    }

    return 0;
}
