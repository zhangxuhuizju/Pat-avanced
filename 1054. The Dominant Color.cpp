#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main(){
	map<long long, int> ma;
	int n, m;
	long long num;
	cin >> n >> m;
	for(int i = 0; i !=m; ++i){
		for(int j = 0; j != n; ++j){
			scanf("%lld",&num);
			ma[num]++;
		}
	}
	int max = 0;
	long long mnum;
	for(auto i = ma.begin(); i != ma.end(); ++i){
		if(i->second > max){
			max = i->second;
			mnum = i->first;
		}	
	}
	cout << mnum << endl;
	return 0;
}
