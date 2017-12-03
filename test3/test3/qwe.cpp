#include<iostream>
using namespace std;
int main()
{
	int n=0;
	char c;
	while((c=getchar())!='\n')
	{
		if(c<='9'&&c>='0'){n++;};
	};
	cout<<n;
}