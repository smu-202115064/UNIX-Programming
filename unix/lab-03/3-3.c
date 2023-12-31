#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int rfd, wfd;
    int n;

    char buf[BUFSIZ];

    rfd = open("3-1.txt", O_RDONLY);
    if (rfd == -1) {
        perror("Open 3-1.txt");
        exit(1);
    }

    wfd = open("3-3.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (wfd == -1) {
        perror("Open 3-3.txt");
        exit(1);
    }

    while ((n = read(rfd, buf, BUFSIZ)) > 0) {
        if (write(wfd, buf, n) != n)
            perror("Write");
    }

    if (n == -1)
        perror("Read");

    close(rfd);
    close(wfd);

    return 0;
}