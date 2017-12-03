#include<math.h>
#include<iostream>
using namespace std;
int x[100];
bool place(int k)
{
	int i;
	for (i = 1;i<k;i++)
		if (x[k] == x[i] || abs(k - i) == abs(x[k] - x[i]))
			return false;
	return true;
}

void queue(int n)
{
	int i, k;
	for (i = 1;i <= n;i++)
		x[i] = 0;
	k = 1;
	while (k >= 1)
	{
		x[k] = x[k] + 1;
		while (x[k] <= n&&!place(k))
			x[k] = x[k] + 1;
		if (x[k] <= n&&k == n) {
			for (i = 1;i <= n;i++)
				cout << x[i]<<" " ;
			cout << endl;
		}
		else if (x[k] <= n&&k<n)
			k = k + 1;
		else
		{
			x[k] = 0;
			k = k - 1;
		}
	}
}

void main()
{
	int n;
	cout << "输入皇后个数n:";
	cin >> n;
	queue(n);
	cin >> n;
}
