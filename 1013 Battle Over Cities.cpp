#include<iostream>
#include<vector>
using namespace std;
int x[500000]={0};
int y[500000]={0};
int findRoot(int x,int* collected){
	if(collected[x]==0) return x;
	else{
		int root=findRoot(collected[x],collected);
		collected[x]=root;
		return root;
	}
}
int main(){
	int n,m,k,check,count;
	cin>>n>>m>>k;
	int* collected=new int[n+1];
	for(int i=0;i!=m;++i){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i!=k;++i){
		for(int j=1;j<=n;++j) collected[j]=0;
		count=0;
		cin>>check;
		for(int j=0;j!=m;++j){
			if(x[j]!=check&&y[j]!=check){
				int rx=findRoot(x[j],collected);
				int ry=findRoot(y[j],collected);
				if(rx!=ry) collected[rx]=ry;
			}
		}
		for(int j=1;j<=n;++j){
			if(collected[j]==0) ++count;
		}
		cout<<count-2<<endl;
	}
	return 0;
}
