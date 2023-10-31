#include <time.h>
#include <stdio.h>


char *output[] = {
    "%x %X",
    "%G년 %m월 %d일 %U주 %H:%M",
    "%r",
    "%a %b %e %T %Y" // ctime() 과 같게.
};

int main() {
    struct tm *tm;
    int n;
    time_t timep;
    char buf[257];

    time(&timep);
    tm = localtime(&timep);

    for (n = 0; n < 4; n++) {
        strftime(buf, sizeof(buf), output[n], tm);
        printf("%s = %s\n", output[n], buf);
    }
}
