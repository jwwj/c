#include<iostream>
using namespace std;
class Person
{
private:
		char strName[10];
		int nAge;
public:
		Person(char*name,int age)
		{
			strcpy_s(strName,name);
			nAge=age;
			cout<<"constructor of person"<<strName<<endl;
		}
		~Person(){cout<<"deconstrutor of person"<<strName<<endl;}
};
class Employee:public Person
{
		char strDept[20];
		Person Wang;
	public:
		Employee(char *name,int age,char *dept,char *namel,int agel):Person(name,age),Wang(namel,agel)
		{
			strcpy(strDept,dept);
			cout<<"constructor of Employee"<<endl;
		}
		~Employee(){cout<<"deconstrutor of Employee"<<endl;}
};
int main()
{
	Person a("liabi",12);
	Employee B("dfdf",22,"asd","asd",456);
}