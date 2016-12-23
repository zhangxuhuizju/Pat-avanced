#include<iostream>
using namespace std;
int main(){
	int k;
	cin>>k;
	int a[55],b[55],c[55];
	for(int i=1;i!=55;++i){
		cin>>a[i];
		b[i]=i;
	}
	for(int m=0;m!=k;++m){
		for(int i=1;i!=55;++i){
			c[a[i]]=b[i];
		}
		for(int i=1;i!=55;++i){
			b[i]=c[i];
		}	
	}
	for(int i=1;i!=55;++i){
		if(c[i]>=1&&c[i]<=13) cout<<"S"<<c[i];
		if(c[i]>=14&&c[i]<=26) cout<<"H"<<c[i]-13;
		if(c[i]>=27&&c[i]<=39) cout<<"C"<<c[i]-26;
		if(c[i]>=40&&c[i]<=52) cout<<"D"<<c[i]-39;
		if(c[i]>52) cout<<"J"<<c[i]-52;
		if(i!=54) cout<<" ";
	}
	return 0;
}
