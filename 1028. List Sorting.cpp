#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct data{
	int id;
	string name;
	int grade;
};
bool cmp1(data a,data b){
	return a.id<b.id;
}bool cmp2(data a,data b){
	if(a.name!=b.name) return a.name<b.name;
	else return a.id<b.id;
}
bool cmp3(data a,data b){
	if(a.grade!=b.grade) return a.grade<b.grade;
	else return a.id<b.id;
}
int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	data s;
	vector<data> v;
	for(int i=0;i!=n;++i){
		scanf("%d",&s.id);
		cin>>s.name;
		scanf("%d",&s.grade);
		v.push_back(s);
	}
	if(c==1) sort(v.begin(),v.end(),cmp1);
	if(c==2) sort(v.begin(),v.end(),cmp2);
	if(c==3) sort(v.begin(),v.end(),cmp3);
	for(int i=0;i!=n;++i){
		
		printf("%.6d %s %d\n",v[i].id,v[i].name.c_str(),v[i].grade);
	}
	return 0;
}
