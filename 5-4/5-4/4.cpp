#include<iostream>
#include<string>
using namespace std;
class Person
{
	string Name;
	string sex;
	int year,moon;
public:
	void intput_p()
	{
		cout<<"name:";cin>>Name;
		cout<<"sex:";cin>>sex;
		cout<<"year:";cin>>year;
		cout<<"moon:";cin>>moon;
	};
	void output_p()
	{
		cout<<"name:"<<Name<<endl;
		cout<<"sex:"<<sex<<endl;
		cout<<"year:"<<year<<endl;
		cout<<"moon:"<<moon<<endl;
	};
};
class Student:public Person
{
	int Class;
	int Number;
	string zhuan;
	double english;
	double math;
public:
	void input_s()
	{
		intput_p();
		cout<<"class:";cin>>Class;
		cout<<"number:";cin>>Number;
		cout<<"zhuanye:";cin>>zhuan;
		cout<<"english:";cin>>english;
		cout<<"math:";cin>>math;
	};
	void output_s()
	{
		output_p();
		cout<<"class:"<<Class<<endl;
		cout<<"number:"<<Number<<endl;
		cout<<"zhuanye:"<<zhuan<<endl;
		cout<<"english:"<<english<<endl;
		cout<<"math:"<<math<<endl;
	};
};
class Employee:public Person
{
	string bumen;
	string zhiwu;
	int gongzi;
public:
	void input_e()
	{
		intput_p();
		cout<<"bumen:";cin>>bumen;
		cout<<"zhiwu:";cin>>zhiwu;
		cout<<"gongzi:";cin>>gongzi;
	};
	void output_e()
	{
		output_p();
		cout<<"bumen:"<<bumen<<endl;
		cout<<"zhiwu:"<<zhiwu<<endl;
		cout<<"gongzi:"<<gongzi<<endl;
	};
};
int main()
{
	int i;
	cout<<"----------------------------------------------"<<endl;
	cout<<"Please input your choose:"<<endl;
	cout<<"1.Student\n2.Empoyee"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cin>>i;
	cout<<"----------------------------------------------"<<endl;
	switch(i)
		{
		case 1:{
				Student stu1;
				cout<<"Please input the student infomations:"<<endl;
				cout<<"----------------------------------------------"<<endl;
				stu1.input_s();
				cout<<"----------------------------------------------"<<endl;
				cout<<"The student infomation is:"<<endl;
				cout<<"----------------------------------------------"<<endl;
				stu1.output_s();
				break;
				};
		case 2:{
				Employee emp1;
				cout<<"Please input the employee infomations:"<<endl;
				cout<<"----------------------------------------------"<<endl;
				emp1.input_e();
				cout<<"----------------------------------------------"<<endl;
				cout<<"The employee infomation is:"<<endl;
				cout<<"----------------------------------------------"<<endl;
				emp1.output_e();
				break;
			   };
		};
}