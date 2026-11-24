#include<stdio.h>

void task0(void) { printf("task0 is called!\n");}
void task1(void) { printf("task1 is called!\n");}
void task2(void) { printf("task2 is called!\n");}
void task3(void) { printf("task3 is called!\n");}
void task4(void) { printf("task4 is called!\n");}
void task5(void) { printf("task5 is called!\n");}
void task6(void) { printf("task6 is called!\n");}
void task7(void) { printf("task7 is called!\n");}

void execute(void (*funcs[])(void), int n)
{
	for (int i = 0; i < n; i++)
		funcs[i]();
	//这里funcs是一个函数，funcs[i]()是在调用这个函数
	//也就是调用chosen[i]() 而chosen[i]中目前储存的是tasks[ch - '0']
}

void scheduler(void)
{
	void (*tasks[8])(void) = {task0, task1, task2, task3, task4, task5, task6, task7};
	//函数名退化为指针，tasks是函数指针类型的数组
	//task[0] = task0
	
	static void (*chosen[100005])(void); //后面这个框里的void指不需要接收什么数据就进行这个操作
	//chosen是函数指针类型的数组，存放的是指针
	//用static把数组放在静态存储区，不占用函数栈避免爆掉
	int cnt = 0;
	int ch;
	
	while ((ch = getchar()) != EOF && ch != '\n')
	{
		if (ch >= '0' && ch <= '7')
			chosen[cnt++] = tasks[ch - '0'];
	}
	
	execute(chosen, cnt);
}

int main()
{
	scheduler();
	return 0;
}
