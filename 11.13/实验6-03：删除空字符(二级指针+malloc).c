#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void trim_merge(char *s)
{
	char *r = s; //读指针
	char *w = s; //写指针
	int started = 0; //碰上第一个非空白字符前为0
	int follow_space = 0; //上一个是空格时为1
	
	while(*r != '\0')
	{
		if (*r == ' ' || *r == '\t')
		{
			if(!started) //前导空白
			{
				r++;
				continue;
			}
			if(*r == ' ')
			{
				if(!follow_space) //上一个不是空格时写入
				{
					*w++ = *r;
					follow_space = 1; //空格状态改变
				}
			}
			else //*r == '\t'
			{
				*w++ = *r;
				follow_space = 0;
			}
		}
		else //*r既不是空格也不是tab
		{
			*w++ = *r;
			follow_space = 0;
			started = 1;
		}
		r++;
	}
	*w = '\0';
}

int main()
{
	//读入一整行带空格的文本要用fgets
	int n = 0;
	scanf("%d", &n);
	getchar(); //吃掉换行
	
	//用二级指针(指向指针的指针)
	//第一级指向哪一行,第二级指向哪一个
	char **lines = (char **)malloc(n * sizeof(char *));
	char buf[82];
	//lines是整个指针数组的首地址
	//lines[i]是第i行字符串的首地址==*(lines+i)
	//lines[i][j]是第i行第j个字符==*(*(lines+i)+j)
	
	for (int i = 0; i < n; i++)
	{
		fgets(buf, sizeof(buf), stdin);
		buf[strcspn(buf, "\n")] = '\0';
		
		trim_merge(buf);
		//此时buf已经完成变化
		
		int len = (int)strlen(buf);
		lines[i] = (char *)malloc((len + 1) * sizeof(char));
		if (lines[i] == NULL) return 1;
		strcpy(lines[i], buf); //把buf复制进去
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", lines[i]);
		free(lines[i]);
	}
	
	free(lines);
	return 0;
}
