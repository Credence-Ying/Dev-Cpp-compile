#include<stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	//逐字节取出来的话，要用指向char的指针，指向int的指针每次变动是4字节
	unsigned char *p = (unsigned char *)&x;
	
	for (int i = 3; i >= 0; i--)
	{
		unsigned char hi = p[i] >> 4;
		unsigned char lo = p[i] & 0x0f;
		
		putchar((hi < 10) ? '0' + hi : 'A' + hi - 10);
		putchar((lo < 10) ? '0' + lo : 'A' + lo - 10);
	}
	putchar('\n');
	return 0;
}
