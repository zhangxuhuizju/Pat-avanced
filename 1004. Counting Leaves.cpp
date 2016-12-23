#include<iostream>
#include<vector>
using namespace std;
struct tree{
	int child[100];
	int childnum;
	int parent;
	int level;
	tree():parent(-1),childnum(0){}
}t[100];
int main(){
	int n,m,maxlevel=0;
	int getnode[100]={0};
	int parent,child;
	cin>>n>>m;
	for(int i=0;i!=m;++i){
		cin>>parent;
		cin>>t[parent].childnum;
		getnode[parent]=1;
		for(int j=0;j!=t[parent].childnum;++j){
			cin>>child;
			getnode[child]=1;
			t[child].parent=parent;
			t[parent].child[j]=child;
		}
	}
	t[1].level=0;
	getnode[1]=1;
	for(int i=1;i!=100;++i){
		if(getnode){
			for(int j=0;j!=t[i].childnum;++j){
				t[t[i].child[j]].level=t[i].level+1;
				if(t[i].level+1>maxlevel) maxlevel=t[i].level+1;
			}
		}
	}
	vector<tree> v[maxlevel+1];
	for(int i=1;i!=100;++i){
		if(getnode[i]) v[t[i].level].push_back(t[i]);
	}
	int flag=0;
	for(int i=0;i!=maxlevel+1;++i){
		int num=0;
		for(int j=0;j!=v[i].size();++j){
			if(v[i][j].childnum==0) ++num;
		}
		if(flag==0){
			cout<<num;
			flag=1;
		}
		else cout<<" "<<num;
	}
	cout<<endl;
	return 0;
} 
