#include <iostream>
using namespace std;
 class Point{
	   public:
         Point(int a, int b):x(a),y(b){ }
         int getx() {return x;}
         int gety() {return y;}
      private:
          int x,y;
      };

class Shape{
 	   public: Shape(Point p):p1(p){ }
               virtual double area()=0;
      private:
          Point p1;
};
class Rectangle: public Shape {
   public:Rectangle( Point pr,int x, int y):Shape(pr),len(x),wid(y) { }
        int get_len() {return len; }
        int get_wid() {return wid; }
        double area() {return len*wid; }
     private:int len;
           int wid;
};
class Circle: public Shape {
     public: Circle(Point pc, int x):Shape(pc),r(x) { }
           double area() {return r*r*3.14;}
   private: int r;
};
class Square: public Rectangle {
      public:Square(Point ps,int x): Rectangle(ps,x,x){ }
};
int main()
{
	int x,y,len,wid,rad;

	cin>>x>>y>>len>>wid;
	Point p1(x,y);
	cout<<"p1 has been constructed"<<endl<<endl;
	Rectangle r1(p1,len,wid);
	cout<<"r1 has been constructde"<<endl;


	cin>>x>>y>>rad;
	Point p2(x,y);
	Circle c1(p2,rad);
	cout<<"c1 has been constructed"<<endl;
	

	cin>>x>>y>>len;
	Point p3(x,y);
	Square s1(p3,len);
	cout<<"s1 has been constructed"<<endl;

	getchar();

		return 0;
}

