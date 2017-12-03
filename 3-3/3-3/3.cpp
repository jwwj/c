#include<iostream>
using namespace std;
class Score
{
	int No;
	char Name[4];
	double Math,Phi,Data;
	double Ave;
public:
	Score(){}
	void Write();
	double Average();
	void Display();
};
void Score::Write()
{
	cin>>No>>Name>>Math>>Phi>>Data;
};
double Score::Average()
{
	Ave=(Math+Phi+Data)/3;
	return Ave;
};
void Score::Display()
{
	cout<<No<<" "<<Name<<" "<<Math<<"   "<<Phi<<"   "<<Data<<"   "<<Ave<<endl;
};
int main()
{
	Score a1,a2,a3;
	cout<<"Input number name math phi data:"<<endl;
	a1.Write();
	a1.Average();
	a2.Write();
	a2.Average();
	a3.Write();
	a3.Average();
	cout<<"Êý¾Ý°üº¬£º"<<endl;
	cout<<"No   "<<"Name "<<"Math "<<"Phi "<<"Data "<<"Ave"<<endl;
	a1.Display();
	a2.Display();
	a3.Display();
}