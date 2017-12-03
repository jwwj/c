#include<iostream>
using namespace std;
void fnl(int z=5);
int x=1,y=2;
int main()
{
	cout<<"Begin..."<<endl;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	cout<<"Evaluate x and y in main()..."<<endl;
	int x=10,y=20;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	cout<<"Step into fnl()..."<<endl;
	fnl();
	fnl(10);
	cout<<"Back in main"<<endl;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	return 0;
}
void fnl(int z)
{
	static int x=100;
	int y=200;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	x=x+y+z;
}