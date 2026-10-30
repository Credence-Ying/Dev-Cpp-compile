#include<stdio.h>

int ch;

int main()
{
	while((ch = getchar()) != EOF)
	{
		ch = (ch >= 'A' && ch <= 'Z') ? (ch - 'A' + 'a') : ch; //ch - 'A' + 'a'也可以写为 ch + 32 因为ASCII码中a在A后32个
		putchar(ch);
	}
	return 0;
}
