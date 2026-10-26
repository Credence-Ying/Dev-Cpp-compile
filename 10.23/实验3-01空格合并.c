#include<stdio.h>

int ch;
enum {CHAR,BEGIN,SPACE};
int state = CHAR;

int main()
{
	do
	{
		ch = getchar();
		switch(state)
		{
			case CHAR:
				putchar(ch);
				if (ch == ' ') state = BEGIN;
				break;
			case BEGIN:
				if (ch == ' ') state = SPACE;
				else
				{
					putchar(ch);
					state = CHAR;
				}
				break;
			case SPACE:
				if (ch == ' ') state = SPACE;
				else
				{
					state = CHAR;
					putchar(ch);
				}
				break;
		}
	}while(ch != '!' && ch != EOF);
	return 0;
}
