#include<iostream>
using namespace std;

int BinarySearchRecursive(int *array, int low, int high, int key);

int main() {
	int n;
	cin >> n;
	//��̬��������a[2][n]
	int **a = new int *[2];
	for (int i = 0;i < 2;i++)
		a[i] = new int[n];

	int k,p,flag=0;//flag��ʾ���鵱ǰ����
	for (int i = 0;i < n;i++) {
		cin >> p;
		k = BinarySearchRecursive(a[0], 0, flag, p);
		if (k != -1) {	//k��=1�������ҵ���Ԫ��
			a[1][k]++;
			k = -1;
		}
		else {			//k==-1������û���ҵ���ͬԪ�� ���ڿհ״������Ԫ��
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
//���ֲ���
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