#include<cstdio>
using namespace std;
struct roots{
	int root;
	roots():root(-1){}
}R[10001];
int findRoot(int n){
	while( R[n].root != n ){
		n = R[n].root;
	}
	return n;
}
int main(){
	int n, m, bird, mb = 0, mt = 0;
	int root, n1, n2;
	scanf("%d", &n);
	for(int i = 0; i != n; ++i){
		scanf("%d", &m);
		for(int j = 0; j != m; ++j){
			scanf("%d", &bird);
			if( j == 0 ){
				root = bird;
				if(R[root].root == -1){
					R[root].root = root;
					++mb;
				} 	
			}
			if(R[bird].root == -1){
				++mb;
				R[bird].root = root;
			}else{
				n1 = findRoot(root);
				n2 = findRoot(bird);
				R[n2].root = n1;
			}
		}
	}
	for(int i = 0; i != 10001; ++i){
		if(R[i].root == i) ++mt;
	}
	printf("%d %d\n", mt, mb);
	scanf("%d", &n);
	for(int i = 0; i != n; ++i){
		scanf("%d %d",&n1, &n2);
		if(R[n1].root == -1 || R[n2].root == -1) printf("No\n");
		else if( mt == 1 ) printf("Yes\n");
		else{
			if(findRoot(n1) == findRoot(n2)) printf("Yes\n");
			else printf("No\n");
		}	
	}
	return 0;
}
