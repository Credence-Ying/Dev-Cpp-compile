#include<stdio.h>

void reverseline()
{
	int ch = getchar();
	if (ch == '\n' || ch == EOF) return;
	reverseline();
	putchar(ch);
}

int main()
{
	reverseline();
	putchar('\n');
	return 0;
}
