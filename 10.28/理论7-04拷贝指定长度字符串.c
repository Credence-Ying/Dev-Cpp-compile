#include<stdio.h>
#include<string.h>

int lens = 0, lent = 0;

void strnCpy(char s[], const char t[], int n)
{
	if(lens <= n)
	{
		for (int i = 1; i <= lens; i++) s[i] = t[i];
	}
	else
	{
		for (int i = 1; i <= n; i++) s[i] = t[i];
	}
}

int main(void)
{ 	
	char s[1005], t[1005];
	int n = 0;

	for (int i = 1; ;i++)
	{
		scanf("%c", &s[i]);
		lens++;
		if(s[i] == ' ') break;
	}
	for (int i = 1; ;i++)
	{
		scanf("%c", &t[i]);
		lent++;
		if(t[i] == ' ') break;
	}
	scanf("%d", &n);
	
	strnCpy(s, t, n);
	
	for (int i = 1; i <= lens; i++) printf("%c", s[i]);
	return 0;
}
