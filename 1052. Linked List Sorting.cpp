#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct link{
	int num;
	int next;
	int add;
}L[100000];

bool cmp(link a, link b){
	return a.num < b.num;
}

int main(){
	int n, begin, add;
	scanf("%d %d", &n, &begin);
	for(int i = 0; i != n; ++i){
		scanf("%d", &add);
		L[add].add = add;
		scanf("%d %d", &L[add].num, &L[add].next);
	}
	vector<link> v;
	add = begin;
	n = 0;
	while( add != -1 ){
		v.push_back(L[add]);
		++n;
		add = L[add].next;
	}
	if(v.size()){
		sort(v.begin(), v.end(), cmp);
		printf("%d %.5d\n", n, v[0].add);
		for(int i = 0; i != n; ++i){
			if(i != n-1 )
				printf("%.5d %d %.5d\n", v[i].add, v[i].num, v[i+1].add);
			else printf("%.5d %d -1", v[i].add, v[i].num);
		}
	}
	else printf("0 -1\n");
	return 0;
}
