#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char ch;
	struct node *next; //链式存储没有顺序,所以在本节点通常要存指向下一节点的地址
}Node;

int main()
{
	Node *head = NULL;
	Node *tail = NULL;
	int c;
	
	//边读边建立链表
	while((c = getchar()) != EOF && c != '\n')
	{
		
		Node *p = (Node *)malloc(sizeof *p);
		if(p == NULL) return 1; //内存申请失败直接返回
		
		p->ch = (char)c;
		p->next = NULL;
		
		if(head == NULL)
			head = tail = p;
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	
	//判断字符的输入
	int chop = 0;
	while((chop = getchar()) != EOF && chop == '\n') {}
	if (chop == EOF) return 0;
	char op = (char)chop;
	
	//判断是否存在
	int found = 0;
	for (Node *p = head; p != NULL; p = p->next)
	{
		if(p->ch == op)
		{
			found = 1;
			break;
		}
	}
	
	//存在的情况：
	if(found)
	{
		Node *prev = NULL; //prev指向前一个没有被删除的节点
		Node *curr = head;
		while(curr != NULL)
		{
			Node *next = curr->next;
			if(curr->ch == op)
			{
				if(prev == NULL) head = next; //删除的是头节点，那么头节点直接往后移
				else prev->next = next; //删除的不是头节点，prev直接跳过curr指向next
				free(curr);
			}
			else prev = curr;
			curr = next;
		}
	}
	
	//不存在的情况，找最大差值
	else if(head != NULL)
	{
		Node *best = head;
		int best_diff = (op - head->ch);
		if (best_diff < 0) best_diff = -best_diff;
		
		for (Node *p = head; p != NULL; p = p->next)
		{
			int d = (op - p->ch);
			if (d < 0) d = -d;
			if (d > best_diff)
			{
				best_diff = d;
				best = p;
			}
		}
		
		Node *np = (Node *)malloc(sizeof *np);
		if (np == NULL) return 1;
		np->ch = op;
		np->next = best->next;
		best->next = np;
		
	}
	
	//遍历记录长度
	int len = 0;
	for (Node *p = head; p != NULL; p = p->next) len++;
	
	//建立无冗余的字符数组
	char *buf = (char *)malloc((len + 1) * sizeof *buf);
	if(buf == NULL) return 1;
	
	int i = 0;
	for (Node *p = head; p != NULL; p = p->next) buf[i++] = p->ch;
	buf[i] = '\0'; //这里的buf[i]等价于*(buf+i),是一个地址的解指针对应的元素
	
	printf("%s\n", buf);
	
	free(buf);
	while(head != NULL)
	{
		Node *t = head;
		head = head->next;
		free(t); //先保存下一个再free当前,如果先free当前就找不到下一个了
	}
	
	return 0;
}
