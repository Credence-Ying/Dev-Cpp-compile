#include<stdio.h>
#include<math.h>

#define S(a, b, c) (((a) + (b) + (c)) / 2.0)

#define AREA(a,b,c) (sqrt(S(a,b,c) * (S(a,b,c) - (a)) * (S(a,b,c) - (b)) * (S(a,b,c) - (c))))

int main()
{
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	
	printf("s=%.2lf\n", S(a,b,c));
	printf("area=%.2lf\n", AREA(a,b,c));
	return 0;
}
