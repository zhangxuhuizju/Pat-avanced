#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int max = 1;
	int temp1 = 1;
	int temp2 = 1;
	int j,k;
	for(int i=0; i!=s.length(); ++i){
		temp1 = 1;
		temp2 = 1;
		j = i - 1;
		k = i + 1;
		while( j >= 0 && k <s.length() && s[j] == s[k]){
			--j;
			++k;
			temp1 += 2;
		}
		j = i;
		k = i + 1;
		while( j >= 0 && k <s.length() && s[j] == s[k]){
			--j;
			++k;
			temp2 += 2;
		}
		--temp2;
		if(temp1>max) max = temp1;
		if(temp2>max) max = temp2;
	}
	cout<<max<<endl;
	return 0;
}
