#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long a[n+1]={0},total=0,distance;
	for(int i=2;i<=n;++i){
		cin>>a[i];
		total+=a[i];
		a[i]+=a[i-1];
	}
	cin>>a[0]; total+=a[0];
	int m,begin,end;
	cin>>m;
	for(int i=0;i!=m;++i){
		cin>>begin>>end;
		if(begin>end) distance=a[begin]-a[end];
		else distance=a[end]-a[begin];
		if(total-distance<distance) distance=total-distance;
		cout<<distance<<endl;
	}
	return 0;
}
