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
	cout<<"请输入您在中国银行的存款额：";
	cin>>A;
	cout<<"请输入您在工商银行的存款额：";
	cin>>B;
	cout<<"请输入您在农业银行的存款额：";
	cin>>C;
	CBabk a(A);
	BBabk b(B);
	GBank c(C);
	total=a.balance+b.balance+c.balance;
	return total;
};
int main()
{
	cout<<"在这三家银行的总存款数为："<<total()<<endl;
}