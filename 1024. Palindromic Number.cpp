#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<cstdlib>
using namespace std;
int main() {
	string n, n1, n2;
	int k, flag = 0,step=-1;
	cin >> n >> k;
	for (int i = 0; i != k; ++i) {
		n1 = n;
		n2 = n;
		reverse(n2.begin(), n2.end());
		if (n1 == n2) {
			step = i;
			break;
		}
		flag = 0;
		for (int j = n1.length() - 1; j >= 0;--j) {
			if (n1[j]-'0' + n2[j] - '0'+flag >= 10) {
				n[j] = n1[j] + n2[j] + flag -10- '0';
				flag = 1;
			}
			else {
				n[j] = n1[j] + n2[j] + flag - '0';
				flag = 0;
			}
		}
		if (flag) n = "1" + n;
	}
	if (step == -1) cout << n << endl << k << endl;
	else cout << n << endl << step << endl;
	return 0;
}
