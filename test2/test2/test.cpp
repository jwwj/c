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
	cout<<"��������������"<<endl;
	cin>>a>>b>>c;
	cout<<"����������˫������"<<endl;
	cin>>d>>e>>f; 
	cout<<"ǰ���������нϴ���ǣ�"<<max(a,b)<<endl;
	cout<<"���������ǣ�"<<max(a,b,c)<<endl;
	cout<<"ǰ����˫�������нϴ���ǣ�"<<max(d,e)<<endl;
	cout<<"����˫�������ǣ�"<<max(d,e,f)<<endl;
	return 0;
}