#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, sum = 0;

    /**
     * 0번 인자에는 자신(프로그램)이 주어지므로 해당 인자를 생략하고,
     * 사용자가 문자의 형태로 입력한 인자들을 숫자로 파싱하여 누적 합을 구한다.
     */
    for(i = 1; i < argc; i++)
        sum += atoi(argv[i]);

    printf("%d\n", sum);
    return 0;
}