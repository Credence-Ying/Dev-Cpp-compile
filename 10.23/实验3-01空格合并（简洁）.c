#include<stdio.h>

int ch, state = 0;

int main()
{
	do
	{
		ch = getchar();
	    if (ch == ' ')
	    {
	        if (!state) { putchar(' '); state = 1; }
	    }
	    else
	    {
	        putchar(ch);
	        state = 0;
	    }
	}while(ch != '!' && ch != EOF);
	return 0;
}
