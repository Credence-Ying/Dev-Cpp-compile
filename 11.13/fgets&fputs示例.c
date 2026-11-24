#include<stdio.h>

int main()
{
	char ch[105];
	fgets(ch, sizeof(ch), stdin);
	fputs(ch, stdout);
	return 0;
}
