#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *str;

    /**
     * 앞서 선언한 문자 포인터 str에 1Byte(char의 크기)x20 의 크기를 할당한다.
     * Heap 영역에 할당되므로, 반드시 추후에 메모리 공간을 반납해야 할 것 이다.
     */
    str = malloc(sizeof(char) * 20);

    /**
     * str이 가리키는 주소로 부터 6Byte 크기의 공간에 {'H','e','l','l','o','\0'}를 복사한 뒤,
     * printf() 호출을 통해 해당 문자열을 화면에 출력한다.
     */
    strcpy(str, "Hello");
    printf("%s\n", str);

    strcpy(str, "Good morning");
    printf("%s\n", str);

    /**
     * malloc 호출을 이용하여 str에 할당했던 메모리를 반납한다.
     */
    free(str);
    return 0;
}