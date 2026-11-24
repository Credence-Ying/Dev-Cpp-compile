#include <stdio.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX3(a, b, c) MAX(MAX(a, b), c)

#define AVG_ROUND(a, b, c) \
    ((int)round(((double)(a) + (b) + (c)) / 3.0))
//round(a)是四舍五入，返还一个double类型的数

int main(void)
{
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    printf("最大值: %d, 平均值: %d\n",
           MAX3(a, b, c),
           AVG_ROUND(a, b, c));

    return 0;
}
