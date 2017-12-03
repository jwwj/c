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
int i = 0;//节点
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
			printf("该节点的数据是:%c", t->info);
		else {
			n(t->llink,x);
			n(t->rlink,x);
		}
	}
}

void main() {
	NODE *T;
	printf("---------- 实验一 ------------\n");
	printf("请输入一个二叉树：\n");
	creat(T);
	if (!T)
		printf("空树！");
	else{
		n(T);
		printf("该二叉树有%d个子叶节点\n", i);
		int x;
		printf("\n---------- 实验二 ------------\n");
		printf("请输入要查找的位置的节点：");
		scanf_s("%d", &x);
		i = 0;
		n(T, x);
		scanf_s("%d", &x);
	}
}