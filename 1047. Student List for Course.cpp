#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int Hash(char* name){
	return name[3] - '0' + 10*(name[2] - 'A') + 10*26*(name[1] - 'A')
	+ 10*26*26*(name[0] - 'A');
}
char* getName(int i, char* name){
	name[3] = i % 10 + '0';
	i /= 10;
	name[2] = i % 26 + 'A';
	i /= 26;
	name[1] = i % 26 + 'A';
	i /= 26;
	name[0] = i % 26 + 'A';
	name[4] = '\0';
	return name;
}
int main(){
	int n, k;
	scanf("%d %d",&n, &k);
	vector<int> v[2501];
	char name[5];
	int class_;
	int num;
	for(int i = 0; i != n; ++i){
		scanf("%s", name);
		scanf("%d", &num);
		for(int j = 0; j != num; ++j){
			scanf("%d", &class_);
			v[class_].push_back(Hash(name));
		}
	}
	for(int i = 1; i <= k; ++i){
		sort(v[i].begin(), v[i].end());
		printf("%d %d\n", i, v[i].size());
		for(int j = 0; j != v[i].size(); ++j){
			printf("%s\n", getName(v[i][j], name));
		}
	}
	return 0;
}
