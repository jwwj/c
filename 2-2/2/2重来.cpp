#include<iostream>
using namespace std;
int max1(int,int);
int max1(int,int,int);
float max1(float,float);
float max1(float,float,float);
int main()
{
	int i;
	float k,a,b,c;
	cout<<"���������";
	cin>>i;
	cout<<"����2-3������";
	switch(i)
	{
	case 2:{cin>>a>>b;k=max1(a,b);break;}
	case 3:{cin>>a>>b>>c;k=max1(a,b,c);break;}
	}
	cout<<"���ֵΪ��"<<k<<endl;
}
int max1(int a,int b)
{
	return a>b?a:b;
}
int max1(int a,int b,int c)
{
	int k,t;
	k=(a>b)?a:b;
	t=(k>c)?k:c;
	return t;
}
float max1(float a,float b)
{
	return a>b?a:b;
}
float max1(float a,float b,float c)
{
	float k,t;
	k=(a>b)?a:b;
	t=(k>c)?k:c;
	return t;
}