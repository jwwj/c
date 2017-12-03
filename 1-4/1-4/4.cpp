#include<iostream>
using namespace std;
int main()
{
	int a,b,c=0,s=0;
	cout<<"输入矩形的长、宽:";
	cin>>a>>b;
	c=2*(a+b);
	s=a*b;
	cout<<"这个长方形的的周长为："<<c<<"\n这个长方形的面积为："<<s<<endl;
}