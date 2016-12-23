#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct student{
	string name;
	string sexual;
	string id;
	int grade;
};
bool cmp1(student a, student b){
	return a.grade<b.grade;
}
bool cmp2(student a, student b){
	return a.grade>b.grade;
}
int main(){
	int n;
	cin>>n;
	student stu;
	vector<student> M,F;
	for(int i=0; i!=n ;++i){
		cin>>stu.name>>stu.sexual>>stu.id>>stu.grade;
		if(stu.sexual == "M") M.push_back(stu);
		else F.push_back(stu);
	}
	sort(M.begin(),M.end(),cmp1);
	sort(F.begin(),F.end(),cmp2);
	if(F.size() == 0) cout<<"Absent"<<endl;
	else cout<<F[0].name<<" "<<F[0].id<<endl;
	if(M.size() == 0) cout<<"Absent"<<endl;
	else cout<<M[0].name<<" "<<M[0].id<<endl;
	if(F.size() == 0||M.size() == 0) cout<<"NA"<<endl;
	else cout<<F[0].grade-M[0].grade<<endl;
	return 0;
}
