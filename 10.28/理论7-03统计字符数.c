#include<stdio.h>
#include<ctype.h>

int main()
{
	int alpha = 0, num = 0, cnt = 0;
	int ch;
	while((ch = getchar()) != EOF)
	{
		if(isdigit(ch)) num++;
		else if (isalpha(ch)) alpha++;
		else cnt++;
	}
	printf("%d %d %d", num, alpha, cnt);
	return 0;
}
