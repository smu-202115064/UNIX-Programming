#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;
    extern char *optarg;
    extern int optind;

    long r;

    while ((n = getopt(argc, argv, "a:m:")) != -1)
    {
        switch (n)
        {
        case 'a':
            r = 0;
            for (--optind; optind < argc; optind++)
                r = r + atol(argv[optind]);
            break;
        case 'm':
            r = 1;
            for (--optind; optind < argc; optind++)
                r = r * atol(argv[optind]);
            break;
        }
    }
    printf("res = %ld\n", r);
}