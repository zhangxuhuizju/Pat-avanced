#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct window{
	int fintime;
	int time;
	queue<int> que;
	window(){fintime=0;time=0;}
}win[20];
struct people{
	int start;
	int time;
	people(){start=0;time=0;}
}peo[1000];
int main(){
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	for(int i=0;i!=k;++i){
		cin>>peo[i].time;
	}
	int finishnum=0;
	for(int i=0;i!=n*m&&finishnum!=k;++i){
		win[i%n].que.push(i);
		peo[i].start=win[i%n].fintime;
		win[i%n].fintime+=peo[i].time;
		++finishnum;
	}
	int minwin=0;
	int mintime=65536;
	while(finishnum!=k){
		for(int i=0;i!=n;++i){
			if(win[i].time+peo[win[i].que.front()].time<mintime){
				mintime=win[i].time+peo[win[i].que.front()].time;
				minwin=i;
			}
		}
		win[minwin].time+=peo[win[minwin].que.front()].time;
		win[minwin].que.pop();
		win[minwin].que.push(finishnum);
		peo[finishnum].start=win[minwin].fintime;
		win[minwin].fintime+=peo[finishnum].time;
		++finishnum;
		minwin=0;
		mintime=65536;
	}
	int people,time,hour,min;
	for(int i=0;i!=q;++i){
		cin>>people;
		if(peo[people-1].start>=540) cout<<"Sorry"<<endl;
		else{
			time=peo[people-1].start+peo[people-1].time;
			hour=8+time/60;
			min=time%60;
			printf("%.2d:%.2d\n",hour,min);
		}
	}
	return 0;
}
