#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;
    /**
     * unistd.h 헤더에 포함된 optarg, optind, getopt() 를 불러와 사용한다.
     * 외부 파일에서 선언된 변수를 사용할 것이므로 optarg, optind 변수에는 extern 키워드를 붙여서 선언한다.
    */
    extern char *optarg;
    extern int optind;

    long r;

    /**
     * "a:m:"에서 각 알파벳은 사용가능한 옵션들을 의미하고, 콜론 기호는 해당 옵션에는 인자가 필요함을 의미한다.
     * getopt() 함수를 통해 argc, argv 변수로 전달된 파라미터들로 부터 옵션을 추출하고, optind, optarg 변수로 해당 옵션의 순서와 값을 조회할 수 있다.
    */
    while ((n = getopt(argc, argv, "a:m:")) != -1)
    {
        switch (n)
        {
        case 'a':
            /**
             * 옵션 a가 주어지면, 후행으로 오는 인자(long 타입의 정수)를 모두 더한다.
            */
            r = 0;
            for (--optind; optind < argc; optind++)
                r = r + atol(argv[optind]);
            break;
        case 'm':
            /**
             * 옵션 m이 주어지면, 후행으로 오는 인자(long 타입의 정수)를 모두 곱한다.
            */
            r = 1;
            for (--optind; optind < argc; optind++)
                r = r * atol(argv[optind]);
            break;
        }
    }
    /**
     * 연산 결과를 출력한다.
    */
    printf("res = %ld\n", r);
}