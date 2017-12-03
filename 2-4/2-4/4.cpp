#include<iostream>
using namespace std;
double s=0;
double round(double r)
{
	s=3.14*r*r;        
	return s;
};
double chang(double a,double b)
{        
	s=a*b;
	return s;
};
double zheng(double a)
{        
	s=a*a;
	return s;
};
int main()
{        
	int k;        
	cout<<"1.圆形\n2.长方形\n3.正方形\n"<<endl;
	cin>>k;
	switch(k)
	{        
case 1:                  
	{
		int r;                   
		cout<<"输入半径：";
		cin>>r;                   
		cout<<"面积为："<<round(r)<<endl;
		break;
	}        
case 2:
	{
		int a,b;
		cout<<"输入长与宽：";
		cin>>a>>b;
		cout<<"面积为："<<chang(a,b)<<endl;
		break;
	}        
case 3:
	{
		int a;
		cout<<"输入边长：";
		cin>>a;
		cout<<"面积为："<<zheng(a)<<endl;
		break;
	}
	return 0;
	}
}
