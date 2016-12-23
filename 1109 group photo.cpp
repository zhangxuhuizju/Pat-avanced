#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct student{
	string name;
	int hight;
};
bool cmp(student a,student b){
	if(a.hight!=b.hight) return a.hight>b.hight;
	else return a.name<b.name;
}
int main(){
	int n,k;
	cin>>n>>k;
	student stu[n];
	for(int i=0;i!=n;++i){
		cin>>stu[i].name>>stu[i].hight;
	}
	sort(stu,stu+n,cmp);
	int num=n/k;
	string group="";
	int maxnum=num+n%k;
	group=stu[0].name;
	for(int i=1;i<maxnum;i++){
		if(i%2!=0){
			group=stu[i].name+" "+group;
		}else group=group+" "+stu[i].name;
	}
	cout<<group<<endl;
	int t=maxnum;
	while(t!=n){	
		group=stu[t].name;
		for(int i=1;i<num;i++){
			if(i%2!=0){
				group=stu[i+t].name+" "+group;
			}else group=group+" "+stu[i+t].name;
		}
		cout<<group<<endl;
		t+=num;	
	}
	return 0;	
}
