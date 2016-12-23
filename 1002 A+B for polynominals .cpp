#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	double poly[1001]={0};
	int flag[1001]={0};
	int k,num,count=0;
	cin>>k;
	for(int i=0;i!=k;++i){
		scanf("%d",&num);
		scanf("%lf",&poly[num]);
		if(!flag[num]){
			++count;
			flag[num]=1;
		}
	}
	cin>>k;
	double temp;
	for(int i=0;i!=k;++i){
		scanf("%d",&num);
		if(!flag[num]){
			++count;
			flag[num]=1;
			scanf("%lf",&poly[num]);
		}else{
			scanf("%lf",&temp);
			poly[num]+=temp;
			if(poly[num]==0){
				--count;
				flag[num]=0;	
			}
		}
	}
	cout<<count;
	for(int i=1000;i>=0;--i){
		if(poly[i]) printf(" %d %.1lf",i,poly[i]);
	}
	cout<<endl;
	return 0;
}
