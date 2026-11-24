#include <stdio.h>
#include <string.h>

char line[100];

int main()
{
	if (fgets(line, sizeof(line), stdin) != NULL) {
	    line[strcspn(line, "\n")] = '\0';   /* 去掉换行 */
	    printf("%s\n", line);
	}
	return 0;
	
	scanf(" %[^\n]", line);
	//%[^\n]的意思是读到换行符为止，注意前面一定要加个空格跳过先前所有空白字符，要不然上一行有残留的话会失败
}
