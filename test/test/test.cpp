#include<iostream>
#include<vector>
int main()
{
using namespace std;
vector<int>i_elem;
int temp;
while(cin>>temp && temp>0)
  i_elem.push_back(temp);
cout<<"you entered "<<i_elem.size()<<endl;
}