#include <stdio.h> 
#include<windows.h>
#define MAX 100   
void main() {
	int a[MAX];
	int i, j, n;
	printf("请输入记录的总个数。\n");
	scanf_s("%d", &n);
	printf("请输入各记录（仅输入关键字）\n");
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	a[0] = a[1];
	i = 1;
	j = n;
	while (i < j) {
		while (i < j&&a[j] <= 0)	--j;
		a[i] = a[j];
		while (i < j&&a[i] >= 0)	++i;
		a[j] = a[i];
	}
	a[i] = a[0];
	for (i = 1; i <= n; i++) {
		printf("%4d", a[i]);
	}
	printf("\n");
	system("pause");
}