#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#define MAX 26*26*26*10
using namespace std;

int name2index(char *name){
	return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+name[3]-'0';
}
vector<int> students[MAX];
int main(){
	char name[5];
	int n,k,index,num,studentId;

	scanf("%d %d",&n,&k);
	while(k--){
		scanf("%d %d",&index,&num);
		while(num--){
			scanf("%s", name);
			studentId = name2index(name);
			students[studentId].push_back(index);
		}
	}

	while(n--){
		scanf("%s", name);
		printf("%s ",name);
		studentId = name2index(name);
		printf("%d",students[studentId].size());
		sort(students[studentId].begin(), students[studentId].end());
		for(vector<int>::iterator it=students[studentId].begin(); it!=students[studentId].end(); it++){
			printf(" %d",*it);
		}
		
		printf("\n");
	}
	return 0;
}
