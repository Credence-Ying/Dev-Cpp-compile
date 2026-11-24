#include<stdio.h>

int main()
{
	char s[200];
	for (int i = 0; i < 128; i++) scanf("%c", &s[i]);
	
	char seg[8][5]; //最后还要存一个\0
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int val = 0; //val存每4个二进制数对应的十六进制数多大
			for (int k = 0; k < 4; k++)
			{
				int pos = i * 16 + j * 4 + k; //pos对应输入的128位中的位置
				val = val * 2 + (s[pos] - '0');
			}
			seg[i][j] = "0123456789abcdef"[val]; //相当于取这个字符串的第val位，这一步很巧妙
		}
		seg[i][4] = '\0'; //补上结束符让每段成为合法字符串，这样后面可以用%s来输出
	}
	//这一步就把128位二进制数转成了8*4的十六进制数
	
	for (int i = 0; i < 8; i++)
	{
		int k = 0;
		while(seg[i][k] == '0' && seg[i][k+1] != '\0') k++; //这一步后可以判断有k个前导0,有3个或4个0的时候k都为3
		if (k > 0) //有前导0才要去除
		{
			int t = 0;
			for (int j = k; seg[i][j] != '\0'; j++)
				seg[i][t++] = seg[i][j]; //从第k位开始搬：k搬到0，k+1搬到1....
			seg[i][t] = '\0';
		}
	}
	//这一步去除了每一个十六进制数的前导0,还把全0的四位缩成一位0
	
	//找最长的首次出现的全0数段
	//第一次想用enum和state来写，后来想到更简单的方法
	int iszero[8] = {0};
	for (int i = 0; i < 8; i++) iszero[i] = (seg[i][0] == '0'); //如果是0段那么判断式为真，iszero[i] == 1;
	
	int zerostart = -1, zerolen = 0;
	for (int i = 0; i < 8; i++)
	{
		if(!iszero[i]) continue; //不是0段直接跳过
		int j = i;
		while(j < 8 && iszero[j]) j++;
		int len = j - i;
		if (len >= 2 && len >= zerolen)
		{
			zerostart = i;
			zerolen = len;
		}
		i = j - 1;
	}
	//现在zerostart记录最长0段起始位置，zerolen记录最长0段长度
	
	if (zerostart == -1) //没有0段需要压缩
	{
		for (int i = 0; i < 8; i++)
		{
			printf("%s", seg[i]);
			if(i != 7) putchar(':');
		}
	}
	else //有0段要压缩
	{
		for (int i = 0; i < zerostart; i++)
		{
			printf("%s", seg[i]);
			if(i != 7 && i != zerostart - 1) putchar(':');
		}
		printf("::");
		for (int i = zerostart + zerolen; i < 8; i++)
		{
			printf("%s", seg[i]);
			if(i != 7) putchar(':');
		}
	}
	putchar('\n');
	return 0;
}
