#include<iostream>
#include<math.h>
using namespace std;
class CBabk
{
	double balance;
public:
	CBabk(double x):balance(x){};
	friend double total();
	
};
class BBabk
{
	double balance;
public:
	BBabk(double x):balance(x){};
	friend double total();
};
class GBank
{
	double balance;
public:
	GBank(double x):balance(x){};
	friend double total();
};
double total()
{
	double total=0;
	double   A,B,C;
	cout<<"�����������й����еĴ��";
	cin>>A;
	cout<<"���������ڹ������еĴ��";
	cin>>B;
	cout<<"����������ũҵ���еĴ��";
	cin>>C;
	CBabk a(A);
	BBabk b(B);
	GBank c(C);
	total=a.balance+b.balance+c.balance;
	return total;
};
int main()
{
	cout<<"�����������е��ܴ����Ϊ��"<<total()<<endl;
}