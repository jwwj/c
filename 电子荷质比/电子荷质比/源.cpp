#include<iostream>
using namespace std;
int main() {
	float x,b,e;
	cin >> x;
while (1){
	b = 0.85*1.257*pow(10, -6)*5714.3*x;
	cin >> x;
	e = (8 * 3.14*3.14*x) / (b*b*0.15*0.15);
	cout << e << endl;
	cin >> x;
}}