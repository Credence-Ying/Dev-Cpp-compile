#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[10005] = {0};
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int cnt = 0;
    // 标准冒泡排序
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                cnt++;   // 每次相邻交换计数 +1
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}
