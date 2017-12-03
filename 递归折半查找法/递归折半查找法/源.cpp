#define MAXNUM 20
#include <stdio.h>
#include <Windows.h>

typedef struct sSTable
{
	int a[MAXNUM + 1];
	int lenth;
}SSTable, *SSTable_;

void Structure(SSTable_ ST);//初始化ST成员
int Binsearch(SSTable ST, int key, int low, int high);//折半查找递归算法

void main()
{
	int t;

	SSTable ST;
	Structure(&ST);

	printf("请输入要查找的数:");
	scanf_s("%d", &t);

	if (Binsearch(ST, t, 1, ST.lenth))
		printf("查找成功！！\n\n");

	system("pause");
}

//初始化ST成员
void Structure(SSTable_ ST)
{
	printf("输入数组(用0作为结束输入的标识)：");

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

//折半查找递归算法
int Binsearch(SSTable ST, int key, int low, int high)
{
	int mid;	//中值
	int i = 0;	//记录查找到的KEY的位置
	mid = (low + high) / 2;
	if (low <= high)
	{
		if (key == ST.a[mid])	return mid;
		else if (key < ST.a[mid])	i = Binsearch(ST, key, low, mid - 1);
		else 	i = Binsearch(ST, key, mid + 1, high);
	}
	return i;
}
