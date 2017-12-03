#include<iostream>
using namespace std;
class Circle
{
public:	
	Circle(double r):rad(r){}
	double area(){return 3.14*rad*rad;}
private:
	double rad;
};
class Rectangle
{
public:
	Rectangle(double l,double w):len(l),wid(w){}
	double area(){return len*wid;}
private:
	double len,wid;
};
class Square
{
public:
	Square(double l):len(l){}
	double area(){return len*len;}
private:
	double len;
};
int main()
{
	cout<<"Input shape"<<endl;
	cout<<"if cricle,input c;\nif rectangle input r;\nif square input s."<<endl;
	char shape;
	cin>>shape;
	switch(shape)
	{
	case'c':{
				double r;
				cout<<"input radius"<<endl;
				cin>>r;
				Circle  r1(r);
				cout<<"circle area="<<r1.area()<<endl;
				break;
			}
	case'r':{
				double len,wid;
				cout<<"Input length and width"<<endl;
				cin>>len>>wid;
				Rectangle r2(len,wid);
				cout<<"Rectangle area="<<r2.area()<<endl;
				break;
			}
	case's':{
				double len;
				cout<<"input length"<<endl;
				cin>>len;
				Square r3(len);
				cout<<"Square area="<<r3.area()<<endl;
				break;
			}
	default:cout<<"input error"<<endl;
		break;
	}
	getchar();
	return 0;
}