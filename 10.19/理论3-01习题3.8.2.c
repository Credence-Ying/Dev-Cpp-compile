#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    const char *hex = "0123456789abcdef";
    char ch;
    char *p;

    scanf(" %c", &ch);

    p = strchr(hex, tolower(ch)); //如果找到了则p存了对应的地址
    if (p != NULL) printf("%d\n", p - hex); //用p存储的地址减去hex开头的地址刚好就是数字大小
    else printf("%c\n", ch);

    return 0;
}
