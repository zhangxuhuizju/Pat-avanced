#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct student{
	string id;
	int grade;
	int group;
	int trank;
	int grank;
};
bool cmp(student a,student b){
	if(a.grade!=b.grade) return a.grade>b.grade;
	else return a.id<b.id;
}
int main(){
	int total=0,n,peonum;
	cin>>n;
	student stu;
	vector<student> v[n+1];
	for(int i=1;i<=n;++i){
		cin>>peonum;
		total+=peonum;
		for(int j=0;j!=peonum;++j){
			cin>>stu.id>>stu.grade;
			stu.group=i;
			v[i].push_back(stu);	
		}	
	}
	cout<<total<<endl;
	for(int i=1;i<=n;++i) sort(v[i].begin(),v[i].end(),cmp);
	int rank=0;
	for(int i=1;i<=n;++i){
		rank=1;
		v[i][0].grank=1;
		for(int j=1;j!=v[i].size();++j){
			rank++;
			if(v[i][j-1].grade!=v[i][j].grade){
				v[i][j].grank=rank;
			}else v[i][j].grank=v[i][j-1].grank;	
		}
		for(int j=0;j!=v[i].size();++j) v[0].push_back(v[i][j]);
	}
	sort(v[0].begin(),v[0].end(),cmp);
	rank=1;
	v[0][0].trank=1;
	for(int i=1;i!=v[0].size();++i){
		rank++;
		if(v[0][i-1].grade!=v[0][i].grade){
				v[0][i].trank=rank;
			}else v[0][i].trank=v[0][i-1].trank;
	}
	for(int i=0;i!=v[0].size();++i){
		cout<<v[0][i].id<<" "<<v[0][i].trank<<" "
			<<v[0][i].group<<" "<<v[0][i].grank<<endl;
	}
	return 0;
} 
