//c++中二维数组在函数间传递需要用二维数组的指针int **a；
//如果函数要返回多个值的话，需要把返回的值放在一个结构体中，并返回该结构体
/*
 *动态建立二维数组
 *	int **b = new int *[p1.n];
 *		for (int i = 0;i < p1.n;i++)
 *			b[i] = new int[p1.m];
 */
#include<iostream>
using namespace std;

struct pic{
	int n;	//行
	int m;  //列  
};

pic input_nm();				//输入行列
int **paint(int n,int m);	//获取用户输入数组
void right(int **a, pic p);	//消除行相同数
void down(int **a, pic p);	//消除列相同数

int main() {

	pic p1;
	p1 = input_nm();
	int **a = paint(p1.n, p1.m);
	
	//对二维数组a进行拷贝
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

	right(a, p1);	//消除行相同数
	down(b, p1);	//消除列相同数


	//输出
	
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

	//暂停屏幕
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
		cout << "输入错误" << endl;
		return 0;
	}
	else {
		a = new int *[n];
		for (int i = 0;i < n;i++)
			a[i] = new int[m];
		//i行j列
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
				while (k == a[i][j + 1]) {	//统计相同数保存在flag中
					k = a[i][j + 1];
					flag++;
					j++;
					if (j+1 > p.m) {
						break;
					}
				}
		}
			if (flag >= 2) {	//从当前元素位置开始，往左删除flag个数
				a[i][j] = 0;
				while(flag) {
					a[i][j - flag] = 0;
					flag--;
				}
			}else{
				flag = 0;	//换行时防止累计上一行中的flag
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
				while (k == a[i + 1][j]) {	//统计相同数保存在flag中
					k = a[i + 1][j];
					flag++;
					i++;
					if (i + 1 > p.n - 1) {
						break;
					}
				}
			}

			if (flag >= 2) {	//从当前元素位置开始，往下删除flag个数
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
