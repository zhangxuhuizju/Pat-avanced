#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool comp(string a, string b){
	if(a[0] != b[0]) return a[0] < b[0];
	else return a + b < b + a;
}
int main(){
	int n, flag = 0;
	cin >> n;
	string* num = new string[n];
	for(int i = 0; i != n; ++i){
		cin >> num[i];
	}
	sort(num, num+n, comp);
	for(int i=0; i!=n; ++i){
		if( !flag ){
			for(int j = 0; j != num[i].length(); ++j){
				if(num[i][j] != '0' && flag == 0){
					flag = 1;
					cout << num[i][j];
				}else if(flag == 1){
					cout << num[i][j];
				}
			}
		}else cout << num[i];
	}
	if( flag == 0 ) cout << "0"; 
	cout << endl;
	delete[] num;
	return 0;
} 
