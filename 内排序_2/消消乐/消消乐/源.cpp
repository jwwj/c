//c++�ж�ά�����ں����䴫����Ҫ�ö�ά�����ָ��int **a��
//�������Ҫ���ض��ֵ�Ļ�����Ҫ�ѷ��ص�ֵ����һ���ṹ���У������ظýṹ��
/*
 *��̬������ά����
 *	int **b = new int *[p1.n];
 *		for (int i = 0;i < p1.n;i++)
 *			b[i] = new int[p1.m];
 */
#include<iostream>
using namespace std;

struct pic{
	int n;	//��
	int m;  //��  
};

pic input_nm();				//��������
int **paint(int n,int m);	//��ȡ�û���������
void right(int **a, pic p);	//��������ͬ��
void down(int **a, pic p);	//��������ͬ��

int main() {

	pic p1;
	p1 = input_nm();
	int **a = paint(p1.n, p1.m);
	
	//�Զ�ά����a���п���
	int **b = new int *[p1.n];
	for (int i = 0;i < p1.n;i++)
		b[i] = new int[p1.m];

	for (int i = 0; i < p1.n; i++)
	{
		for (int j = 0; j < p1.m; j++)
		{
			b[i][j] = a[i][j];
		}
	}

	right(a, p1);	//��������ͬ��
	down(b, p1);	//��������ͬ��


	//���
	
	for (int i = 0; i < p1.n; i++)
	{
		for (int j = 0; j < p1.m; j++)
		{
			if (b[i][j] == 0) {
				a[i][j] = 0;
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	//��ͣ��Ļ
	int x;
	cin >> x;

	return 0;
}
pic  input_nm() {
	pic p;
	cin >> p.n >> p.m;
	return p;
}
int **paint(int n,int m){
	int **a;
	if (n < 1 || m>30) {
		cout << "�������" << endl;
		return 0;
	}
	else {
		a = new int *[n];
		for (int i = 0;i < n;i++)
			a[i] = new int[m];
		//i��j��
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		return a;
	}
}



void right(int **a,pic p) {	
	int k;
	int flag = 0;
	for (int i=0;i < p.n;i++) {
		for (int j = 0;j < p.m;j++) {

			k = a[i][j];
			if (j + 1 <= p.m - 1) {
				while (k == a[i][j + 1]) {	//ͳ����ͬ��������flag��
					k = a[i][j + 1];
					flag++;
					j++;
					if (j+1 > p.m) {
						break;
					}
				}
		}
			if (flag >= 2) {	//�ӵ�ǰԪ��λ�ÿ�ʼ������ɾ��flag����
				a[i][j] = 0;
				while(flag) {
					a[i][j - flag] = 0;
					flag--;
				}
			}else{
				flag = 0;	//����ʱ��ֹ�ۼ���һ���е�flag
			}
		}
	}
}

void down(int **a, pic p) {
	int k;
	int flag = 0;
	for (int j = 0;j < p.m;j++) {
		for (int i = 0;i < p.n;i++) {

			k = a[i][j];
			if (i + 1 <= p.n - 1) {
				while (k == a[i + 1][j]) {	//ͳ����ͬ��������flag��
					k = a[i + 1][j];
					flag++;
					i++;
					if (i + 1 > p.n - 1) {
						break;
					}
				}
			}

			if (flag >= 2) {	//�ӵ�ǰԪ��λ�ÿ�ʼ������ɾ��flag����
				a[i][j] = 0;
				while (flag) {
					a[i - flag][j] = 0;
					flag--;
				}
			}
			else {
				flag = 0;	
			}
		}
	}
}
