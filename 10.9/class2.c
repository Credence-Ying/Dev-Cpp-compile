#include<stdio.h>

int ch = 0;
int chcnt = 0;
int rowcnt = 0;

int main()
{
	printf("输入Ctrl+Z以终止输入");
	while((ch = getchar()) != EOF)
	{
		chcnt++;
		if (ch == '\n') rowcnt++;
	}
	printf("字符数:%d, 行数:%d", chcnt, rowcnt);
	return 0;
}

//getchar 和 putchar 是通用的按照字符流的形式处理单个字符的工具
