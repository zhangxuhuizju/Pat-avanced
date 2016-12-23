#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int max=0;
	int a[n],b[n];
	for(int i=0;i!=n;++i){
		cin>>a[i];
		b[i]=a[i];
		
	}
	sort(a,a+n);
	int num[n],amount=0;
	for(int i=0;i!=n;++i){
		if(b[i]>max) max=b[i];
		if(max==b[i]&&a[i]==b[i]) num[amount++]=a[i];
	}
	cout<<amount<<endl;
	for(int i=0;i!=amount;++i){
		if(i==0) cout<<num[i];
		else cout<<" "<<num[i];
	}
	cout<<endl;
	return 0;	
}
