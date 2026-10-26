#include<stdio.h>
#include<stdbool.h>

int n = 0;
int k = 0;
int a[25] = {0};
int cnt = 0;
int ans = 0;

bool prime(int a) //判断质数
{
	if (a < 2) return false;
	for (int i = 2; i*i <= a; i++) //只用判断到根号a就行了，否则可能超时
	{
		if (a % i == 0) return false;
	}
	return true;
}

void dfs(int t, int start) //要求排列而非组合,只要从前往后搜索就行
{
	if (t > k) //某一次的停止条件
	{
		if (prime(cnt) == 1) ans++;
		return; //记得返回跳出dfs
	}
	
	for (int i = start; i <= n; i++) //是n不是k这样才能够遍历所有数据
	{
		cnt += a[i];
		dfs(t + 1, i + 1);
		cnt -= a[i];
	}
	//用start确保从前往后选,因此不再需要visited做判断
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dfs(1,1);
	printf("%d", ans);
	return 0;
}
