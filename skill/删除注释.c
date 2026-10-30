#include<stdio.h>
enum {COPY, START, COMMENT, END};

int main()
{
	char c;
	int state = COPY;
	printf("input C program end with Ctrl+z:\n");
	while((c = getchar()) != EOF)
	{
		switch(state)
		{
			case COPY:
				if (c == '/') state = START;
				else putchar(c);
				break;
			case START:
				if (c == '*') state = COMMENT;
				else
				{
					putchar('/');
					state = (c == '/') ? START : (putchar(c),COPY);
				}
				break;
			case COMMENT:
				if (c == '*') state = END;
				break;
			case END:
				state = (c == '/') ? COPY : ((c == '*') ? END : COMMENT);
		}
	}
	return 0;
}
