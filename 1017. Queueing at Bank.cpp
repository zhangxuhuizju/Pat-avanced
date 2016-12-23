#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct people{
	int h,m,s;
	int spend;
}p;
bool cmp(people a,people b){
	if(a.h!=b.h) return a.h<b.h;
	else if(a.m!=b.m) return a.m<b.m;
	else return a.s<b.s;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<people> v;
	for(int i=0;i!=n;++i){
		scanf("%d:%d:%d %d",&p.h,&p.m,&p.s,&p.spend);
		if(p.h>=17&&p.s+p.m>=1) continue;
		v.push_back(p);
	}
	if(v.size()<=k) printf("0.0\n");
	else{
		sort(v.begin(),v.end(),cmp);
		double wait=0;
		int total=v.size();
		int* time=new int[k];
		for(int i=0;i!=k;++i) time[i]=28800;
		for(int i=0;i!=k;++i){
			if(v[i].h*3600+v[i].m*60+v[i].s<28800){
				wait+=28800-v[i].h*3600-v[i].m*60-v[i].s;
				time[i]=28800+60*v[i].spend;
			}else{
				time[i]=v[i].h*3600+v[i].m*60+v[i].s+v[i].spend*60;
			}
		}
		for(int i=k;i!=v.size();++i){
			sort(time,time+k);
			if(v[i].h*3600+v[i].m*60+v[i].s<time[0]){
				wait+=time[0]-v[i].h*3600-v[i].m*60-v[i].s;
				time[0]+=v[i].spend*60;
			}else{
				time[0]=v[i].h*3600+v[i].m*60+v[i].s+v[i].spend*60;
			}
		}
		printf("%.1lf\n",wait/60/total);
	}
	return 0;
} 
