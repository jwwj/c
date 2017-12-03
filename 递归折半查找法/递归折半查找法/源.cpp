#define MAXNUM 20
#include <stdio.h>
#include <Windows.h>

typedef struct sSTable
{
	int a[MAXNUM + 1];
	int lenth;
}SSTable, *SSTable_;

void Structure(SSTable_ ST);//��ʼ��ST��Ա
int Binsearch(SSTable ST, int key, int low, int high);//�۰���ҵݹ��㷨

void main()
{
	int t;

	SSTable ST;
	Structure(&ST);

	printf("������Ҫ���ҵ���:");
	scanf_s("%d", &t);

	if (Binsearch(ST, t, 1, ST.lenth))
		printf("���ҳɹ�����\n\n");

	system("pause");
}

//��ʼ��ST��Ա
void Structure(SSTable_ ST)
{
	printf("��������(��0��Ϊ��������ı�ʶ)��");

	int t;
	ST->lenth = 0;
	scanf_s("%d", &t);
	while (t != 0)
	{
		ST->a[ST->lenth + 1] = t;
		++ST->lenth;
		scanf_s("%d", &t);
	}
}

//�۰���ҵݹ��㷨
int Binsearch(SSTable ST, int key, int low, int high)
{
	int mid;	//��ֵ
	int i = 0;	//��¼���ҵ���KEY��λ��
	mid = (low + high) / 2;
	if (low <= high)
	{
		if (key == ST.a[mid])	return mid;
		else if (key < ST.a[mid])	i = Binsearch(ST, key, low, mid - 1);
		else 	i = Binsearch(ST, key, mid + 1, high);
	}
	return i;
}
