#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FLASE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;

typedef struct LNode{
	//线性表的单链表存储结构
	struct LNode *next;
	float coef;//系数
}LNode;

typedef struct LNode *LinkList;

Status InitList(LinkList &L) {
	//构造一个空的线性表
	L = (LinkList)malloc(sizeof(LNode));
	if (L) {
		L->next = NULL;
		return OK;
	}
	else
		return ERROR;
}

Status ListInsert(LinkList &L, int i, float c) {
	//i为插入位置,c为多项式的系数，j为计数器
	int j = 1;
	LinkList p, s;
	p = L;

	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j>i) {
		return ERROR;
	}

	s = (LinkList)malloc(sizeof(LNode));
	s->coef = c;
	
	s->next = p->next;
	p->next = s;
}

void CreatPolyon(LinkList &L){
	int i;

	int m = -1;
	float c = 0;

	LinkList p;
	p = L;

	L->coef = 0.0;
	
	do{
		printf("请输入多项式的项数：\n");
		scanf_s("%d", &m);
		if (m < 0) {
			printf("请输入正确的项数！");
		}
	} while ((m < 0) && (m != (int)m));

	printf("请依次输入各项的系数：\n");
	for (i = 1;i <= m; ++i) {
		scanf_s("%f", &c);
		ListInsert(L, i, c);
	};

	printf("您输入的多项式如下：\n");
	for (i;i > 1;i--) {
		p = p->next;
		printf("%f ", p->coef);
	}
	printf("\n");
}

int main(){
	LinkList A, B, C;
	InitList(A);
	InitList(B);
	InitList(C);

	printf("----------多项式A---------\n");
	CreatPolyon(A);
	printf("----------多项式B---------\n");
	CreatPolyon(B);
	
	int k;
	scanf_s("%d", &k);
}