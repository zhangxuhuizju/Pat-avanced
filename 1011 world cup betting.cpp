#include<iostream>
#include<stdio.h>
using namespace std;
int findMax(double *a){
	if(a[0]>=a[1]&&a[0]>=a[2]) return 0;
	else if(a[1]>=a[0]&&a[1]>=a[2]) return 1;
	else return 2;
}
int main(){
	double a[3][3];
	for(int i=0;i!=3;++i){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	double max=1;
	int num;
	for(int i=0;i!=3;++i){
		num=findMax(a[i]);
		if(num==0) cout<<"W ";
		if(num==1) cout<<"T ";
		if(num==2) cout<<"L ";
		max*=a[i][num];
	}
	max=max*1.3-2;
	printf("%.2lf\n",max);
	return 0;
}
