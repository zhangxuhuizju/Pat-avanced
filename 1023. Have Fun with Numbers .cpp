#include<iostream>
#include<string>
using namespace std;
int main(){
	string num;
	cin>>num;
	int a1[10]={0},b1[10]={0};
	int* a=new int[num.length()];
	int* b=new int[num.length()];
	for(int i=0;i!=num.length();++i){
		a[i]=num[i]-'0';
		++a1[a[i]];
	}
	int flag=0;
	for(int i=num.length()-1;i>=0;--i){
		if(a[i]*2+flag>=10){
			b[i]=a[i]*2+flag-10;
			++b1[b[i]];
			flag=1;
		}else{
			b[i]=a[i]*2+flag;
			++b1[b[i]];
			flag=0;
		}
	}
	if(flag){
		cout<<"No"<<endl<<"""1";
		for(int i=0;i!=num.length();++i) cout<<b[i];
		cout<<endl; 
	}else{
		int flag=1;
		for(int i=0;i!=10;++i){
			if(a1[i]!=b1[i]){
				flag=0;
				break;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		for(int i=0;i!=num.length();++i) cout<<b[i];
		cout<<endl; 
	}
	delete[]a;
	delete[]b; 
	return 0;
}
