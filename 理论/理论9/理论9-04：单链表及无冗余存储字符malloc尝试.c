#include<stdio.h>
#include<stdlib.h>

/*
tail->next = p 等价于 (*tail).next = p;
p->ch 是顺着p的地址找到ch结点的字符 p->next 是顺着p的地址取那个节点的"下一个节点地址"
p = p->next 让p跳到下一节点(跟数组中的i++一个效果)
但是由于链表的内存分散在堆里，不能通过p++的形式一位一位读取(p是指针)
p->next->ch p跳到下一节点再取它对应的字符
p->next == NULL这是最后一个节点，后面没了

每轮循环都会执行一次malloc得到一块新内存，并新建一个全新的p指向它
之后这个p就不再指向上一轮的内存。因此p天然就指向"最新那个结点"，根本不需要移动，它并不负责遍历链表。

真正需要移动的是tail:
tail->next = p; 旧尾巴的next指向新节点
tail = p; tail从旧尾巴挪到新尾巴
*/

/*
把字符从链表搬入buf (把链式存储转换为顺序存储)
① 链表结点地址乱        →  无法用 %s 输出
② malloc 一整块连续内存  →  buf[0] .. buf[len]
③ 顺着 next 搬字符       →  buf[0]='I', buf[1]='L', ...
④ 末尾写 '\0'            →  成为合法 C 字符串
⑤ printf("%s", buf)      →  读到一个字节一个字节，遇 '\0' 停
*/

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
	while((c = getchar()) != EOF)
	{
		if(c == '\n') continue;
		
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
	
	//遍历进行顺序输出，同时记录长度
	int len = 0;
	for (Node *p = head; p != NULL; p = p->next)
	{
		putchar(p->ch);
		len++;
	}
	putchar('\n');
	
	//建立无冗余的字符数组
	char *buf = (char *)malloc((len + 1) * sizeof *buf);
	if(buf == NULL) return 1;
	
	int i = 0;
	for (Node *p = head; p != NULL; p = p->next) buf[i++] = p->ch;
	buf[i] = '\0'; //这里的buf[i]等价于*(buf+i),是一个地址的解指针对应的元素
	
	printf("%d\n", len);
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
