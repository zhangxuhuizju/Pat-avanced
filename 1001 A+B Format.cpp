#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	long long a,b,c;
	cin>>a>>b;
	c=a+b;
	if(c<0){
		cout<<"-";
		c=-c;	
	}
	stringstream stream;
	string num;
	stream<<c;
	stream>>num;
	for(int i=0;i<num.length();++i){
		cout<<num[i];
		if((num.length()-i-1)%3==0&&i!=num.length()-1) cout<<",";
	}
	return 0;
} 
