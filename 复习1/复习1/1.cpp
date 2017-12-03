#include<iostream>
using namespace std;
class re
{
	int left_x,left_y;
	int right_x,right_y;
public:
	re(){};
	void input();
	void output();
};
void re::input()
{
	cin>>left_x>>left_y>>right_x>>right_y;
};
void re::output()
{
	cout<<left_x<<left_y<<right_x<<right_y;
};
int main()

{
	re a;
	a.input();
	a.output();
}