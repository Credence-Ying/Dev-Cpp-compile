#include<stdio.h>
#include<ctype.h>

int atoh(const char nstr[])
{
	int i = 0, value = 0;
	if (nstr[0] == '0' && (nstr[1] == 'x' || nstr[1] == 'X')) i = 2;
	
	for(; nstr[i] != '\0'; i++)
	{
		int d = 0;
		if (isdigit((unsigned char)nstr[i]) ) d = nstr[i] - '0';
		else if (nstr[i] >= 'a' && nstr[i] <= 'z') d = nstr[i] - 'a' + 10;
		else if (nstr[i] >= 'A' && nstr[i] <= 'Z') d = nstr[i] - 'A' + 10;
		else continue;
		
		value = value * 16 + d;
	}
	return value;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	char s[1005];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		printf("%d ", atoh(s));
	}
	return 0;
}
