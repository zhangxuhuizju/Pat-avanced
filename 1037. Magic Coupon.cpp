#include<iostream>
#include<vector>
#include<algorithm>
bool cmp(long long a, long long b){
	return a>b;
}
bool cmp1(long long a, long long b){
	return a<b;
}
using namespace std;
int main(){
	int n,m;
	cin>>n;
	long long total=0;
	vector<long long> a,a1,b,b1;
	long long num; 
	for(int i=0; i!=n; ++i){
		cin>>num;
		if(num>0) a.push_back(num);
		else if(num<0) a1.push_back(num);
	}
	cin>>m;
	for(int i=0; i!=m; ++i){
		cin>>num;
		if(num>0) b.push_back(num);
		else if(num<0) b1.push_back(num);
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	sort(a1.begin(),a1.end(),cmp1);
	sort(b1.begin(),b1.end(),cmp1);
	for(int i=0; i!=a.size()&&i!=b.size(); ++i){
		total += a[i]*b[i];
	}
	for(int i=0; i!=a1.size()&&i!=b1.size(); ++i){
		total += a1[i]*b1[i];
	}
	cout<<total<<endl;
	return 0;
}
