#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	long long n, m, num;
	vector<long long> v;
	scanf("%lld",&n);
	for(int i=0; i != n; ++i){
		scanf("%lld",&num);
		v.push_back(num);	
	}
	scanf("%lld",&m);
	for(int i=0; i != m; ++i){
		scanf("%lld",&num);
		v.push_back(num);	
	}
	sort(v.begin(),v.end());
	cout<<v[(m+n-1)/2]<<endl;
	return 0;
}
