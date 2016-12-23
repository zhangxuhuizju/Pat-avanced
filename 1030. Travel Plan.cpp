#include<iostream>
#include<vector>
#define max 65536
using namespace std;
int g[500][500];
int c[500][500];
int n,m,s,d;
void initial(int n){
	for(int i=0;i!=n;++i){
		for(int j=0;j!=n;++j){
			g[i][j]=c[i][j]=max;
		}
	}
	return;
}
void djikstra(int s,int d){
	int* visited=new int[n];
	int* path=new int[n];
	int dist=max;
	int min=max;
	for(int i=0;i!=n;++i){
		visited[i]=0;
		if(g[s][i]==max) path[i]=-1;
		else path[i]=s;
	}
	visited[s]=1;
	while(1){
		dist=max;
		min=max;
		for(int i=0;i!=n;++i){
			if(visited[i]==0&&g[s][i]<dist){
				dist=g[s][i];
				min=i;
			}
		}
		if(min==max) break;
		visited[min]=1;
		for(int i=0;i!=n;++i){
			if(visited[i]==0&&g[min][i]!=max){
				if(g[s][i]>g[min][i]+g[s][min]){
					g[s][i]=g[min][i]+g[s][min];
					c[s][i]=c[min][i]+c[s][min];
					path[i]=min;
				}else if(g[s][i]==g[min][i]+g[s][min]&&visited[i]==0){
					if(c[s][i]>c[min][i]+c[s][min]){
						c[s][i]=c[min][i]+c[s][min];
						path[i]=min;
					}
				}
			}
		}
	}
	vector<int> v;
	v.push_back(d);
	int i=d;
	while(path[i]!=s){
		i=path[i];
		v.push_back(i);
	}
	v.push_back(s);
	for(int j=v.size()-1;j>=0;--j) cout<<v[j]<<" ";
	cout<<g[s][d]<<" "<<c[s][d]<<endl;
}
int main(){
	cin>>n>>m>>s>>d;
	initial(n);
	int v,w;
	for(int i=0;i!=m;++i){
		cin>>v>>w;
		cin>>g[v][w]>>c[v][w];
		g[w][v]=g[v][w];
		c[w][v]=c[v][w];
	}
	djikstra(s,d);
	return 0;
}
