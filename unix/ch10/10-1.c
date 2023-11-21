#include <stdlib.h>
#include <stdio.h>

int main( ) {
    FILE *fp;
    int a;
    int fd;

    fp = popen("wc -l", "w");
    if (fp == NULL) {
        fprintf(stderr, "popen failed\n");
        exit(1);
    }
    fd = fileno(fp);
    printf("FD: %d\n", fd);

    for (a = 0; a < 100; a++)
        fprintf(fp, "test line\n");

    pclose(fp);
}