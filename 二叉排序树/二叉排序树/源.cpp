#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

//��������������Ľ��
typedef struct sort
{
	int a;  //�ؼ���
	struct sort *L_node;//������
	struct sort *R_node;//���Һ���
}Sort, *Sort_;


Sort_ Structure();//�����û���������ݹ������������
Sort_ Find(Sort_ BS_tree, int a);//���Ҳ���

void main()
{
	int t;
	Sort_ Record;
	Sort_ BS_tree = Structure();//���ú����������������

	printf("������Ҫ���ҵĹؼ���!\n");
	scanf_s("%d", &t);

	if ((Record = Find(BS_tree, t)))
		printf("���ҳɹ���\n", Record->a);
	system("pause");
}

//�����û���������ݹ������������
Sort_ Structure()
{
	Sort_ BS_tree = (Sort_)malloc(sizeof(Sort));
	Sort_ p, s, q;
	int t;

	BS_tree->L_node = BS_tree->R_node = NULL;

	printf("�밴������˳������������Ľ�㣬����0ʱ������\n");
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

		//����Ҫ���벿��
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

//���Ҳ���
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
	printf("���Ҳ��ɹ�!\n");
	return NULL;
}