#include<stdio.h>
#include<ctype.h>

int main()
{
	int ch = getchar();
	int v = -1;
	
	if (isdigit(ch) != 0) v = ch - '0';
	else if (isxdigit(ch) != 0) v = toupper(ch) - 'A' + 10;
	
	if (v >= 0) printf("%d\n", v);
	else printf("%c\n", ch);
	
	return 0;
}
