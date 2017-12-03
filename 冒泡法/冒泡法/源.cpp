#include<stdio.h>
void main()
{
	int a[10] = { 1,3,2,4,5,6,9,8,0,7};
	int	i, j, mid;
	int *p = a;
	for (j = 0;j<9;j++)
	{
		for (i = 0;i<9-j;i++)
		{
			if (*(p + i)>*(p + i + 1))
			{
				mid = *(p + i);
				*(p + i) = *(p + i + 1);
				*(p + i + 1) = mid;
			}
		}
	}
	for (i = 0;i<10;i++)
	{
		printf("%d", *(p + i));
	}
	scanf_s("%d", &i);
}
