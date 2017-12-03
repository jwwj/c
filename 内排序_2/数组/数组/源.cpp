#include<iostream>
using namespace std;

typedef struct {
	int *elem;//数组基址
	int data[1];
	int length;//当前长度
	int listsize;//当前分配的存储容量
}Sqlist;

int Init(Sqlist &L, int length) {
	L.elem = (int *)malloc(sizeof(int));
	if (!L.elem) return 0;
	else {
		L.length = 0;
		L.listsize = length;
		return 1;
	}
}

int main(){
	Sqlist l;
	int d=-1;
	int length = 0;
	cin >> length ;
	if (length <= 0)
	{
		cout << "数据错误！";
		return 0;
	}
	Init(l, length);
	for (int i = 0;i <= length - 1;i++)
	{
		cin >> d;
		l.data[i] = d;
		cout << l.data[i]<<" ";
		l.length++;
	}
	for (int i = 0;i <= length - 1;i++)
		cout << l.data[i] << " ";
	cout << endl;

	int *p, *q;
	p = l.elem;
	q = p;
	cout<<p++;
	

	cin >> d;
}