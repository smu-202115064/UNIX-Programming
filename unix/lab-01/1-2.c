#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /**
     * 사용자의 권한에 대하여 "linux.txt" 파일에 대한 F_OK (파일 존재 여부)를 체크한다.
     * 자세한 것은 `man access` 참조.
     * */
    if (access("linux.txt", F_OK) == -1)
    {
        /**
         * 시스템 혹은 라이브러리 함수 호출 중 가장 최근에 마주했던 오류에 대한 메시지를 Stdard error에 출력한다.
         * 첫 번째 인자로 주어진 것이 문자열이면, 해당 문자열을 출력하고 콜론(:)을 출력한 뒤, 이어서 오류 메시지를 출력한다.
         * 따라서 "linux.txt: <오류 메시지>" 가 stderr에 출력될 것이다.
         * */
        perror("linux.txt");
        exit(1); // 상태(1)를 반환하며 프로그램 종료.
    }
    return 0;
}