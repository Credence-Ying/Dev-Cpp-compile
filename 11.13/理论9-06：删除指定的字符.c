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
	
	for (Node *p = head; p != NULL; p = p->next)
		putchar(p->ch);
	putchar('\n');
	
	while(head != NULL)
	{
		Node *t = head;
		head = head->next;
		free(t); //先保存下一个再free当前,如果先free当前就找不到下一个了
	}
	
	return 0;
}
