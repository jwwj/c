#include<iostream>
#include<math.h>
using namespace std;
class Rectangle
{
	double Left,Top;
	double Right,Bottom;
public:
	Rectangle(double l,double t,double r,double b):Left(l),Top(t),Right(r),Bottom(b){}
	double Diagonal();
	void Show();
};
double Rectangle::Diagonal()
{
	double a,b,k;
	a=Right-Left;
	b=Top-Bottom;
	k=sqrt(a*a+b*b);
	return k;
}
void Rectangle::Show()
{
	cout<<"矩形的左上角坐标为：("<<Left<<","<<Top<<")"<<endl;
	cout<<"矩形的右下角坐标为：（"<<Right<<","<<Bottom<<"）"<<endl;
	cout<<"该矩形的对角线长为："<<Diagonal()<<endl;
}
int main()
{
	Rectangle *r1 = new Rectangle(10, 10, 20, 20);
	r1->Show();
	delete r1;
}