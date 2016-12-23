#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Class{
	string name;
	string signin;
	string signout;
};
bool cmp(Class a,Class b){
	return a.signin<b.signin;
}
bool cmp1(Class a,Class b){
	return a.signout>b.signout;
}
int main(){
	vector<Class>in,out;
	Class read;
	int m;
	cin>>m;
	for(int i=0;i!=m;++i){
		cin>>read.name>>read.signin>>read.signout;
		in.push_back(read);
		out.push_back(read);
	}
	sort(in.begin(),in.end(),cmp);
	sort(out.begin(),out.end(),cmp1);
	cout<<in[0].name<<" "<<out[0].name<<endl;
	return 0;
}
