#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

//构造二叉排序树的结点
typedef struct sort
{
	int a;  //关键字
	struct sort *L_node;//其左孩子
	struct sort *R_node;//其右孩子
}Sort, *Sort_;


Sort_ Structure();//接收用户输入的数据构造二叉排序树
Sort_ Find(Sort_ BS_tree, int a);//查找部分

void main()
{
	int t;
	Sort_ Record;
	Sort_ BS_tree = Structure();//调用函数构造二叉排序树

	printf("请输入要查找的关键字!\n");
	scanf_s("%d", &t);

	if ((Record = Find(BS_tree, t)))
		printf("查找成功！\n", Record->a);
	system("pause");
}

//接收用户输入的数据构造二叉排序树
Sort_ Structure()
{
	Sort_ BS_tree = (Sort_)malloc(sizeof(Sort));
	Sort_ p, s, q;
	int t;

	BS_tree->L_node = BS_tree->R_node = NULL;

	printf("请按照任意顺序输入二叉树的结点，输入0时结束！\n");
	scanf_s("%d", &t);
	if (t != 0)
	{
		BS_tree->a = t;
	}
	scanf_s("%d", &t);

	while (t != 0)
	{
		p = BS_tree;
		q = (Sort_)malloc(sizeof(Sort));
		q->a = t;
		q->L_node = q->R_node = NULL;

		//查找要插入部分
		if (t>p->a)	s = p->R_node;
		else if (t<p->a)	s = p->L_node;
		else s = NULL;
		while (s != NULL)
		{
			p = s;
			if (t>p->a)	s = p->R_node;
			else if (t<p->a)	s = p->L_node;
			else s = NULL;
		}

		if (p->a != t)
		{
			if (t > p->a) p->R_node = q;
			else	p->L_node = q;
		}

		scanf_s("%d", &t);
	}
	return BS_tree;
}

//查找部分
Sort_ Find(Sort_ BS_tree, int a)
{
	Sort_ s;
	Sort_ p = BS_tree;

	if (a>p->a)	s = p->R_node;
	else if (a<p->a)	s = p->L_node;
	else return p;
	while (s != NULL)
	{
		p = s;
		if (a>p->a)	s = p->R_node;
		else if (a<p->a)	s = p->L_node;
		else return p;
	}
	printf("查找不成功!\n");
	return NULL;
}