#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>
typedef struct node{
	int x;
	struct node *next;
}NODE;
void read(NODE *head,int n){
	if(n==0)
		return;
	int x;
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	head->next=p;
	scanf_s("%d",&x);
	p->x=x;
	read(p,n-1);
}
void write(NODE *head,int n){
	NODE *p;
	if(n==0)
		return;
	p=head->next;
	printf("%d ",p->x);
	write(p,n-1);
}
void px(NODE *head,int n){//排序
	if(n==0)
		return;
	int min;
	int i,s=0;
	NODE *p;
	NODE *r;
	NODE *t;
	p=head->next;
	r=head->next;
	t=head;
	min=p->x;
	for(i=0;i<n;i++){
		if(min>p->x){
			min=p->x;
			r=p;
			s=i;
		}
		p=p->next;
	}
	for(i=0;i<s;i++)
		t=t->next;
	t->next=r->next;
	r->next=head->next;
	head->next=r;
	px(head->next,n-1);
}
void main(){
	int n;
	NODE *head;
	head=(NODE *)malloc(sizeof(NODE));
	printf("输入个数n:");
	scanf_s("%d",&n);
	printf("输入%d个数据:\n",n);
	read(head,n);
	printf("您输入的数据为:\n");
	write(head,n);
	printf("\n排序后的数据为:\n");
	px(head,n);
	write(head,n);
	printf("\n");
	system("pause");
}
 
