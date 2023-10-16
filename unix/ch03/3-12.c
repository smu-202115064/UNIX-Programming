#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char buf[BUFSIZ];
    int n;

    realpath("linux.sym", buf);
    printf("linux.sym : REALPATH= %s=n ");
    n = readlink("linux.sym", buf, BUFSIZ);
    if (n == -1) {
        perror("åreadlink");
        exit(1);
    }

    buf[n] = '\0';
    printf("linux.sym: READLINK = %s\n", buf);
}
