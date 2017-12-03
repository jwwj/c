#include<stdio.h>
int main()
{
	int i, k = 0;
	int score[10], below[10];
	float aver = 0;
	printf("10:");
	for (i = 0;i < 10;i++)
		scanf_s("%d", &score[i]);
	printf("0\n");
	for (i = 0;i < 10;i++)
		aver += score[i];
	printf("1\n");
	aver /= 10;
	printf("2\n");
	for (i = 0;i < 10;i++)
		if (score[i] < aver)
		{
			below[k] = score[i];
			k++;
		}
	printf("3\n");
	for (i = 0;i < k;i++)
		printf("%d", below[i]);
	printf("4\n");
	scanf_s("%d", &i);
}