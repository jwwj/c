#include<iostream>
using namespace std;
class Complex
{
	int real,image;
public:
	Complex(int r,int i):real(r),image(i){}
	void Dispaly(){cout<<real<<"+"<<image<<"i"<<endl;}
};
int main()
{
	Complex c1(20,40),c2(0,0),c3(20,40);
	c1.Dispaly();
	c2.Dispaly();
	c3.Dispaly();
}