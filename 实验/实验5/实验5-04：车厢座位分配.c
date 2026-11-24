#include<stdio.h>

char col_to_letter(int col)
{
	switch(col)
	{
		case 1: return 'A';
		case 2: return 'B';
		case 3: return 'C';
		case 4: return 'D';
		case 5: return 'F';
		default: return '?';
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	int buy[1005] = {0};
	int seat[25][10] = {0}; //开二维数组seat[row][col]
	for (int i = 1; i <= n; i++) scanf("%d", &buy[i]);
	
	for (int i = 1; i <= n; i++)
	{
		int k = buy[i];
		int found = 0; //是否找到响铃位置
		int target_row = -1; //最小列
		int target_col_start = -1; //最小列的起始号码
		
		for (int row = 1; row <= 20; row++)
		{
			int col = 1;
			while (col <= 5)
			{
				if (seat[row][col] == 0) //这里可以坐
				{
					int cnt = 0;
					int start = col;
					while (col <= 5 && seat[row][col] == 0)
					{
						cnt++; //cnt表示这一行还有多少空位
						col++; //col最终会加到6
					}
					if (cnt >= k) //空位比要买的多
					{
						target_row = row;
						target_col_start = start;
						found = 1;
						break;
					}
				}
				else col++;
			}
			if (found) break; //如果找到了就不用再找更大的行
		}
		
		if (found) //输出
		{
			for (int i = 0; i < k; i++)
			{
				int col = target_col_start + i;
				seat[target_row][col] = 1;
				if (i == 0) printf("%d%c", target_row, col_to_letter(col));
				else printf(" %d%c", target_row, col_to_letter(col));
			}
			putchar('\n');
		}
		else //找不到相邻的k个座位，开始寻找全局最小标号
		{
			int allocated = 0;
			int first = 1;
			
			for (int row = 1; row <= 20 && allocated < k; row++)
			{
				for (int col = 1; col <= 5 && allocated < k; col++)
				{
					if (seat[row][col] == 0)
					{
						if(first)
						{
							printf("%d%c", row, col_to_letter(col));
							first = 0;
						} 
						else printf(" %d%c", row, col_to_letter(col));
						allocated++;
					}
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
