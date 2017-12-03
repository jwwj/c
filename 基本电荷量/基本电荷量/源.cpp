#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int i = 1;
	int flag = 1;
	while (flag) {
		cout << "-----" << i << "-----\n";
		float e, u;
		int n;
		cout << "input u:";
		cin >> u;
		if (u == '`') break;
		cout << "input e:";
		cin >> e;
		long double q, e_x;
		q = (1 / u)*(1.43*pow(10, -14) / sqrt(pow((e*(1 + 1.96*pow(10, -2)*sqrt(e))), 3)));
		printf("q=%e\n", q);
		n =(int) (q / (1.6*pow(10, -19)));
		printf("n=%d\n", n);
		e_x = q / n;
		printf("e=%e\n", e_x);
		i++;
	}
}