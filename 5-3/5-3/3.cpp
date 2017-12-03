#include<iostream>
using namespace std;
class Archives
{
	int No;
	char Name[8];
	char sex;
	int age;
public:
	Archives(int no,char na[],char s,int a):No(no),sex(s),age(a)
	{strcpy(Name,na);};
	void show()
	{
		cout<<"Number:"<<No<<endl;
		cout<<"Name:"<<Name<<endl;
		cout<<"sex:"<<sex<<endl;
		cout<<"age:"<<age<<endl;
	};
};
class Laborage:public Archives
{
	double SSalary;
	double Security;
	double Fsalary;
public:
	Laborage(int no2,char na2[],char s2,int a2,int ss,int se):Archives(no2,na2,s2,a2),SSalary(ss),Security(se){};
	int Count()
	{
		 Fsalary=SSalary-Security;
		 return Fsalary;
	};
	void Display()
	{
		cout<<"员工档案："<<endl;
		show();
		cout<<"实发工资为："<<Count()<<endl;
	};
};
int main()
{
	Laborage lab(1001,"Chen",'M',21,2000,100);
	lab.Display();
}