#include<iostream>
#include<math.h>
using namespace std;
class Tri
{
	int x,y,z;
	
public:
	Tri(int a,int b,int c):x(a),y(b),z(c){};
	Tri(Tri &t);
	friend double sum(Tri& tri)
	{
		double s;
		double p;
		p=(tri.x+tri.y+tri.z)/2;
		s=sqrt(p*(p-tri.x)*(p-tri.y)*(p-tri.z));
		cout<<"�����ε������߷ֱ�Ϊ��"<<tri.x<<"��"<<tri.y<<"��"<<tri.z<<endl;
		return s;
	}
	
};
int main()
{
	Tri a(3,4,5);
	cout<<"��������ε����Ϊ��"<<sum(a)<<endl;
}