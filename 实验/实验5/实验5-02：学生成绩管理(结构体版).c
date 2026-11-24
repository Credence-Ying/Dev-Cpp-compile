#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAXN 10005
#define NAME_LEN 105

//全篇使用i = 0; i < n的循环下标

typedef struct{
	char name[NAME_LEN];
	int score;
}Student; //用结构体定义，类型名称应该为struct Student，使用typedef给已有变量起名，这么写结果是Student可以直接作为一个类型名称

Student stu[MAXN]; //stu是Student类型的结构体数组
int n = 0;
bool sort = 0;

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", stu[i].name, &stu[i].score); //字符串不用取址符因为字符串名称就代表了首个元素的地址
	}
	
	if (n == 1) printf("1 record was input!\n");
	else printf("%d records were input!\n", n);
}

void sort_score(void)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (stu[j].score < stu[j+1].score) //按照输入先后顺序冒泡排序所以用 < 不用 <= ，小的往后排
			{
				Student temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
			}
		}
	}
	printf("Reorder finished!\n");
	sort = 1;
}

void output(void)
{
	for (int i = 0; i < n; i++) printf("%s %d\n", stu[i].name, stu[i].score);
}

/* 这样采用的是顺序遍历查找，仅适用于数据比较少的部分，下采用二分查找(在确保顺序的情况之下才能使用所以加了bool sort判断)
void find_score(void)
{
	int target = 0;
	scanf("%d", &target);
	
	bool judge = 0;
	for (int i = 0; i < n; i++)
	{
		if(stu[i].score == target)
		{
			printf("%s %d\n", stu[i].name, stu[i].score);
			judge = 1;
		}
	}
	if (judge == 0) printf("not found!\n");
}
*/

void find_score(void)
{
	//二分必须要在排序之后使用所以先判断一下是否排序了
	if (sort == 0) sort_score();
	sort = 1;
	
	int target = 0;
	scanf("%d", &target);
	
	int lo = 0, hi = n - 1, left = -1;
	//第一次二分找到最左侧==target的坐标left
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (stu[mid].score == target)
		{
			left = mid;
			hi = mid - 1;
		}
		else if (stu[mid].score < target) hi = mid - 1;
		else lo = mid + 1;
	}
	
	if (left == -1)
	{
		printf("not found!\n");
		return;
	}
	
	lo = 0, hi = n - 1;
	int right = -1;
	//第二次二分找到最右侧==target的坐标right，整个的作用就是如果有多个score == target可以全部输出
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if(stu[mid].score == target)
		{
			right = mid;
			lo = mid + 1;
		}
		else if (stu[mid].score < target) hi = mid - 1;
		else lo = mid + 1;
	}
	
	for (int i = left; i <= right; i++) printf("%s %d\n", stu[i].name, stu[i].score);
	
	//目前存在的一个问题是：如果没有进行排序操作却先要进行二分查找，查找中将数据排序了而没有恢复
	//解决方法是新开一个结构体数组对原本输入的数据进行储存，二分查找完之后再恢复原结构体数据
}

int main()
{
	int op = 0;
	while(scanf("%d", &op) == 1 && op != 0)
	{
		switch(op)
		{
			case 1: input(); break;
			case 2: sort_score(); break;
			case 3: output(); break;
			case 4: find_score(); break;
			default: break;
		}
	}
	return 0;
}
