#include<stdio.h>
#include<math.h>
 
 int digit(int n, int k)
 {
 	if (pow(10,k) > n) return -1;
 	for (int i = 1; i < k; i++) n /= 10;
	k = n % 10;
	return k;
 }
 
 int main(void)
 {
     int n,k;
     
     scanf("%d%d", &n, &k);
     printf("%d", digit(n,k));
     return 0;
 }
