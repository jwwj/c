#include<iostream>
using namespace std;
int main()
{
	int *p;
	p=new int [10];
	int i,n=0,m=0;
	for(i=0;i<10;i++)
	{
		cin>>p[i];
		if(p[i]>0) n++;
		else if(p[i]<0) m++;
	}
	cout<<"����:"<<n<<"��\n"<<"������"<<m<<"��"<<endl;
}