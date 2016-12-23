#include<iostream>
#include<string>
using namespace std;
int main(){
	string PAT_;
	getline(cin, PAT_);
	long long P = 0, PA = 0, PAT = 0;
	for(int i=0; i != PAT_.length(); ++i){
		if(PAT_[i] == 'P') ++P;
		if(PAT_[i] == 'A') PA = (P + PA)%1000000007;
		if(PAT_[i] == 'T') PAT = (PA + PAT)%1000000007;
	}
	cout << PAT << endl;
	return 0;
} 
