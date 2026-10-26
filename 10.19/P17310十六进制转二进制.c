#include<stdio.h>

int k;
char ch[1000005];
int a[1000005][5];
int mask = 1 << 3;
int temp = 0;

int main()
{
	scanf("%d", &k);
	getchar();
	
	for (int i = 1; i <= k; i++)
	{
		ch[i] = getchar();
		//把ch[i]由字符转换成数字，否则会以ASCII码运算
		//同时避免了改变ch[i]，后续前导零的判断不会出问题
		if (ch[i] >= '0' && ch[i] <= '9')
			temp = ch[i] - '0';
		else if (ch[i] >= 'A' && ch[i] <= 'F')
			temp = ch[i] - 'A' +10;
		else
			temp = ch[i] - 'a' +10;
		
		for (int j = 1; j <= 4; j++)
		{
			a[i][j] = (temp & mask) ? 1 : 0; //十六进制每1个数对应二进制的4个数，用这种方式获得其二进制表达，储存时直接存1 0
			temp <<= 1;
		}
	}
	
	int n = 1, m = 1;
	while (n <= k && ch[n] == '0') n++;
	if(n > k)
	{
		putchar('0');
		return 0;
	}
	while (m <= 4 && a[n][m] == 0) m++;
	for (int i = m; i <= 4; i++) putchar('0' + a[n][i]);
	for (int i = n + 1; i <= k; i++)
	{
		for (int j = 1; j <= 4; j++) putchar('0' + a[i][j]); //putchar比printf更快可以避免TLE
	} 
	return 0;
}
