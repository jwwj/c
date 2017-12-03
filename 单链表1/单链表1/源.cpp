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
	//���Ա�ĵ�����洢�ṹ
	struct LNode *next;
	float coef;//ϵ��
}LNode;

typedef struct LNode *LinkList;

Status InitList(LinkList &L) {
	//����һ���յ����Ա�
	L = (LinkList)malloc(sizeof(LNode));
	if (L) {
		L->next = NULL;
		return OK;
	}
	else
		return ERROR;
}

Status ListInsert(LinkList &L, int i, float c) {
	//iΪ����λ��,cΪ����ʽ��ϵ����jΪ������
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
		printf("���������ʽ��������\n");
		scanf_s("%d", &m);
		if (m < 0) {
			printf("��������ȷ��������");
		}
	} while ((m < 0) && (m != (int)m));

	printf("��������������ϵ����\n");
	for (i = 1;i <= m; ++i) {
		scanf_s("%f", &c);
		ListInsert(L, i, c);
	};

	printf("������Ķ���ʽ���£�\n");
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

	printf("----------����ʽA---------\n");
	CreatPolyon(A);
	printf("----------����ʽB---------\n");
	CreatPolyon(B);
	
	int k;
	scanf_s("%d", &k);
}