#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char wd1[BUFSIZ];

    getcwd(wd1, BUFSIZ);
    printf("wd1 = %s\n", wd1);
}