#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	long long sum=0;
	string num;
	cin>>num;
	string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	for(int i=0;i!=num.length();++i){
		sum+=num[i]-'0';
	}
	stringstream stream;
	stream<<sum;
	stream>>num;
	for(int i=0;i!=num.length();++i){
		if(!i) cout<<str[num[i]-'0'];
		else cout<<" "<<str[num[i]-'0'];
	}
	cout<<endl;
	return 0;
}
