#include<iostream>
using namespace std;
int min(int,int);
int main()
{
	int a,b,c;
	cout<<"input two number:\n";
	cin>>a>>b;
	c=min(a,b);
	cout<<"min="<<c<<endl;
	return 0;
}
int min(int x,int y)
{
	if(x>y) return y;
	else if(x<y) return x;
	else if(x=y) cout<<"ERROR"<<endl;
}
