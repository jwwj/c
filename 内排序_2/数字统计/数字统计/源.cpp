#include<iostream>
using namespace std;

int BinarySearchRecursive(int *array, int low, int high, int key);

int main() {
	int n;
	cin >> n;
	//动态建立数组a[2][n]
	int **a = new int *[2];
	for (int i = 0;i < 2;i++)
		a[i] = new int[n];

	int k,p,flag=0;//flag表示数组当前长度
	for (int i = 0;i < n;i++) {
		cin >> p;
		k = BinarySearchRecursive(a[0], 0, flag, p);
		if (k != -1) {	//k！=1数组中找到该元素
			a[1][k]++;
			k = -1;
		}
		else {			//k==-1数组中没中找到相同元素 需在空白处插入该元素
			a[0][flag] = p;
			a[1][flag] = 1;
			flag++;
		}
	}
	 for (int j = 0;j < flag;j++){
		for (int i = 0;i < 2;i++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int x;
	cin >> x;
}
//二分查找
int BinarySearchRecursive(int *array, int low, int high, int key)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;

	if (array[mid] == key)
		return mid;
	else if (array[mid] < key)
		return BinarySearchRecursive(array, mid + 1, high, key);
	else
		return BinarySearchRecursive(array, low, mid - 1, key);
}