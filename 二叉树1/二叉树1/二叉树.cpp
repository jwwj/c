#include<stdio.h>
#include<malloc.h>
struct node
{
	char info;
	struct node *llink, *rlink;
};
typedef node NODE;
void  creat(NODE* &T){
	char x;
	x = getchar();
	if (x == '#') 
		T = NULL;
	else if (x != '#')
	{
		T = (NODE *)malloc(sizeof(NODE));
		T->info = x;
		creat(T->llink); 
		creat(T->rlink);
	}
}
int i = 0;//�ڵ�
void n(NODE *t) {
	if (t) {
		if ((t->llink == NULL) && (t->rlink == NULL))
			i++;
		n(t->llink);
		n(t->rlink);
	}
}

void n(NODE *t,int x) {
	if (t) {
		i++;
		if (i == x)
			printf("�ýڵ��������:%c", t->info);
		else {
			n(t->llink,x);
			n(t->rlink,x);
		}
	}
}

void main() {
	NODE *T;
	printf("---------- ʵ��һ ------------\n");
	printf("������һ����������\n");
	creat(T);
	if (!T)
		printf("������");
	else{
		n(T);
		printf("�ö�������%d����Ҷ�ڵ�\n", i);
		int x;
		printf("\n---------- ʵ��� ------------\n");
		printf("������Ҫ���ҵ�λ�õĽڵ㣺");
		scanf_s("%d", &x);
		i = 0;
		n(T, x);
		scanf_s("%d", &x);
	}
}