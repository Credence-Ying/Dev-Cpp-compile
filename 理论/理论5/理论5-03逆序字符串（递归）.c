#include<stdio.h>

void reverseline()
{
	int ch = getchar();
	if (ch == '\n' || ch == EOF) return;
	reverseline(); //递归进行下一次输入
	putchar(ch); //一层一层往外输出自动达到“逆序”的效果：输出在递归后通常可以自动达到逆序
}

int main()
{
	reverseline();
	putchar('\n');
	return 0;
}
