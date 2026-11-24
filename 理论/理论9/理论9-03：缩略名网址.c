#include<stdio.h>
#include<string.h>

#define MAXN 1005

typedef struct
{
	char url[MAXN]; //网址
	char abbr[MAXN]; //缩写
	char full[MAXN]; //全称
}web;

web w[MAXN];

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s %s %s", w[i].url, w[i].abbr, w[i].full);
	
	//使用冒泡排序，用strcmp比较字符串大小，字典序大的往后放
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(w[j].abbr, w[j+1].abbr) > 0)
			{
				web t = w[j];
				w[j] = w[j+1];
				w[j+1] = t;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		printf("%s %s %s\n", w[i].url, w[i].abbr, w[i].full);
	
	char key[MAXN];
	scanf("%s", key);
	
	//可以直接遍历用strcmp找对应，但是已经排序于是用二分查找加快速度
	int low = 0, high = n - 1, pos = -1;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		int c = strcmp(w[mid].abbr, key);
		if (c == 0)
		{
			pos = mid;
			break;
		}
		else if (c < 0) low = mid + 1;
		else high = mid - 1;
	}
	if (pos != -1) printf("%s\n", w[pos].url);
	return 0;
}
