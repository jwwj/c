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
	cout<<"1.Բ��\n2.������\n3.������\n"<<endl;
	cin>>k;
	switch(k)
	{        
case 1:                  
	{
		int r;                   
		cout<<"����뾶��";
		cin>>r;                   
		cout<<"���Ϊ��"<<round(r)<<endl;
		break;
	}        
case 2:
	{
		int a,b;
		cout<<"���볤���";
		cin>>a>>b;
		cout<<"���Ϊ��"<<chang(a,b)<<endl;
		break;
	}        
case 3:
	{
		int a;
		cout<<"����߳���";
		cin>>a;
		cout<<"���Ϊ��"<<zheng(a)<<endl;
		break;
	}
	return 0;
	}
}
