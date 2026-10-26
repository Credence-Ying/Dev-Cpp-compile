#include<stdio.h>
#include<math.h>
#include<stdbool.h>

enum {THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8};
int n = 0;
int pw[10] = {0};

bool isperfect(int k)
{
	int orig = k;
	int a[10] = {0};
	int temp = 1;
	int sum = 0;
	while(k > 0)
	{
		a[temp] = k % 10; //a[i]储存第i位
		k /= 10;
		temp++;
	}
	temp--; //用temp代表k的位数
	for (int i = temp; i >= 1; i--)
	{
		sum += pw[a[i]];
	}
	return sum == orig;
}

int main()
{
	int ans[1005] = {0}; 
	
	while((scanf("%d", &n) == 1) && n != 0)
	{
		int t = 1; //t储存有多少个自幂数
		
		for (int d = 0; d <= 9; d++) //pw[i]代表i的n次幂
		{
		    int v = 1;
		    for (int i = 0; i < n; i++) v *= d;
			pw[d] = v;
		}
		
		int high = 0, low = 1;
		for (int i = 1; i < n; i++) low *= 10;
		high = low * 10 - 1;
		
		for (int i = low; i <= high; i++)
		{
			if(isperfect(i))
			{
				ans[t] = i;
				t++;
			}
		}
		t--;
		
		switch(n)
		{
			case 3: printf("3位的水仙花数有:"); break;
			case 4: printf("4位的四叶玫瑰数有:"); break;
			case 5: printf("5位的五角星数有:"); break;
			case 6: printf("6位的六合数有:"); break;
			case 7: printf("7位的北斗星数有:"); break;
			case 8: printf("8位的八仙数有:"); break;
		}
		for (int i = 1; i <= t; i++)
		{
			printf("%d,", ans[i]);
		}
		printf("共%d个\n", t);
	}
	return 0;
}
