#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler() {
    printf("Timer Invoked..\n");
}

int main() {
    struct itimerval it;

    signal(SIGALRM, sig_handler);
    it.it_value.tv_sec = 5;
    it.it_value.tv_usec = 5;
    it.it_interval.tv_sec = 3;
    it.it_interval.tv_usec = 200000;

    if (setitimer(ITIMER_REAL, &it, (struct itimerval *)NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1) {
        if (getitimer(ITIMER_REAL, &it) == -1) {
            perror("getitimer");
            exit(1);
        }
        printf("(timer) %d sec, %d msec. (interval) %d sec, %d msec. \n", (int)it.it_value.tv_sec, (int)it.it_value.tv_usec, (int)it.it_interval.tv_sec, (int)it.it_interval.tv_usec);
        sleep(1);
    }
}