#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num[n];
	int find[100001]={0};
	int count[10]={0};
	for(int i=0;i<n;i++) {
		cin>>num[i];
		++find[num[i]];
	}
	int judge=0;	
	for(int i=0;i!=n;++i){
		if(find[num[i]]==1){
			judge=num[i];
			break;
		}
	}
	if(judge) cout<<judge<<endl;
	else cout<<"None"<<endl;
	return 0;
}
