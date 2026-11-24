#include<stdio.h>
#include<string.h>

int main()
{
	char dest[1005], src[105]; //dest目标串(承受),src源串(给予)
	scanf("%s %s", dest, src);
	
	int length = strlen(dest); //dest字符串的长度(不包含\0)
	printf("%d\n", length);
	
	int judge = strcmp(dest, src); //比较两个字符串(按照字典序)
	printf("%d\n", judge); //从第一个字符开始依次往后比较 dest<src返回负值 dest>src返回正值 dest==src返回0
	
	strcpy(dest, src); //把src的内容复制到dest中(包含\0)
	strcat(dest, src); //把src的内容拼接到dest后
	
	char *p = strchr(dest, 'l'); //查找dest中有无'l'字符,若有则p指向第一个'l';
	printf("%s\n", p); //输出的是从第一个'l'之后的字符串
	printf("%d\n", p - dest); //输出的是第一个'l'之前有多少个字符(不包括'l')(两地址相减)
	
	char *q = strstr(dest, src); //查找dest中有无src子串
	printf("%s\n", q);
	printf("%d\n", p - dest);
	
	memset(dest, '0', sizeof(dest)); //把dest字符串全部设为'0';
	int a[1005];
	memset(a, 0, sizeof(a)); //对整型同样适用
	return 0;
}
