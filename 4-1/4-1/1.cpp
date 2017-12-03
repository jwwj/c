#include<iostream>
using namespace std;
class Base
{
private:
	int x;
	const int a;
	static const int b;
	const int &r;
public:
	Base(int,int);
	void Show()
	{cout<<x<<","<<a<<","<<b<<","<<r<<endl;}
	void Display(const double&r)
	{cout<<r<<endl;}
};
const int Base::b=125;
Base::Base(int i,int j):x(i),a(j),r(x){}
int main()
{
	Base obj1(104,118),obj2(119,140);
	obj1.Show();
	obj2.Show();
	obj2.Display(3.14159);
	return 0;
}