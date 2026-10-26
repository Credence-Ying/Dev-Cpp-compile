#include <stdio.h>
#include <stdbool.h>

#define MAXN 10000

int prime[10005];
int cnt = 0;                 // 素数个数，prime[0..cnt-1]

bool isprime(int k)
{
    if (k < 2) return false;
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0) return false;
    return true;
}

void judge(int n)
{
    for (int i = 0; i < cnt && prime[i] <= n / 2; i++)
    {
        int j = n - prime[i];          // 只需验证另一半是不是素数
        if (isprime(j))
        {
            printf("%d=%d+%d\n", n, prime[i], j);
            return;
        }
    }
}

int main(void)
{
    for (int i = 2; i <= MAXN; i++)
        if (isprime(i)) prime[cnt++] = i;

    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n < 4 || n % 2 != 0) continue;   // 只处理 ≥4 的偶数
        judge(n);
    }
    return 0;
}
