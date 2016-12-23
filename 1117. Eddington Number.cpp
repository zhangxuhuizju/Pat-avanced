#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n;
	scanf("%d",&n);
	int* num = new int[n];
	for(int i = 0; i != n; ++i){
		scanf("%d", num+i);
	}
	sort(num, num+n, cmp); 
	int max = -1;
	for(int i = 0; i != n; ++i){
		if(num[i] > i+1) max = i+1;
		else break;
	}
	if(max == -1) printf("0\n");
	else printf("%d\n",max);
	return 0;
}
