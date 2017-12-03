#include <iostream>
using namespace std;
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}

int max(int a,int b,int c)
{
	if(a>b>c)
	return a;
	else if(c>b>a)
	return c;
	else 
	return b;
}
double max(double a,double b)
{
	if(a>b)
	return a;
	else
	return b;
}
double max(double a,double b,double c)
{
	if(a>b>c)
	return a;
	else if(c>b>a)
	return c;
	else 
	return b;
}
int main()
{
	int a,b,c;
	float d,e,f;
	cout<<"请输入三个整数"<<endl;
	cin>>a>>b>>c;
	cout<<"请输入三个双精度数"<<endl;
	cin>>d>>e>>f; 
	cout<<"前两个整数中较大的是："<<max(a,b)<<endl;
	cout<<"最大的整数是："<<max(a,b,c)<<endl;
	cout<<"前两个双精度数中较大的是："<<max(d,e)<<endl;
	cout<<"最大的双精度数是："<<max(d,e,f)<<endl;
	return 0;
}