#include<stdio.h>

void reverse(int u[],int l,int r)
{
	int t = 0;
	while(l < r)
	{
		t = u[l];
		u[l] = u[r];
		u[r] = t;
		r--;
		l++;
	}
}

void swapsegment(int u[], int n, int k)
{
	reverse(u, 0, k - 1);
	reverse(u, k, n - 1);
	reverse(u, 0, n - 1);
}
//因为不让开辅助数组，所以只能在原本的数组里转三次

int main()
{
	
	int n = 0, k = 0;
	int u[1005] = {0};
	
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &u[i]);
	
	swapsegment(u, n, k);
	
	for (int i = 0; i < n; i++) printf("%d ", u[i]);
	return 0;
}
