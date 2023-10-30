#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>

int main() {
    struct timeval tv;
    time_t tloc;

    gettimeofday(&tv, NULL);
    time(&tloc);

    printf("Time(sec, time) : %d\n", (int) tloc);
    printf("Time(sec, gettimeofday) : %d\n", (int) tv.tv_sec);
    printf("Time(micro-sec) : %d\n", (int) tv.tv_usec);

}