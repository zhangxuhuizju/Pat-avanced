#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
struct student{
	string name;
	double c,m,e,a;
};
int main(){
	int n,m,flag=0;
	cin>>n>>m;
	student* stu=new student[n];
	for(int i=0;i!=n;++i){
		cin>>stu[i].name>>stu[i].c>>stu[i].m>>stu[i].e;
		stu[i].a=(stu[i].m+stu[i].c+stu[i].e)/3;
	}
	string id;
	char best;
	int count,temp,num;
	for(int i=0;i!=m;++i){
		count=best=flag=temp=0;
		cin>>id;
		for(int j=0;j!=n;++j){
			if(stu[j].name==id){
				flag=1;
				num=j;
				break;
			}
		}
		if(flag==0){
			cout<<"N/A"<<endl;
			continue;
		}
		for(int j=0;j!=n;++j){
			if(stu[j].a>stu[num].a) temp++;
		}
		count=temp+1;
		best='A';
		temp=0;
		for(int j=0;j!=n;++j){
			if(stu[j].c>stu[num].c) temp++;
		}
		if(temp+1<count){
			count=temp+1;
			best='C';
		}
		temp=0;
		for(int j=0;j!=n;++j){
			if(stu[j].m>stu[num].m) temp++;
		}
		if(temp+1<count){
			count=temp+1;
			best='M';
		}
		temp=0;
		for(int j=0;j!=n;++j){
			if(stu[j].e>stu[num].e) temp++;
		}
		if(temp+1<count){
			count=temp+1;
			best='E';
		}
		cout<<count<<" "<<best<<endl;
	}
	return 0;
}
