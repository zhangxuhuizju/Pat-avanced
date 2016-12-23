#include<iostream>
using namespace std;
int best[201][10001] = {0};
int max(int a, int b, int c){
	if(a >= b && a >= c) return a;
	if(b >= a && b >= c) return b;
	if(c >= a && c >= b) return c;
}
int main(){
	int n, m, k, flag = 0;
	cin >> n;
	cin >> m;
	int* fa = new int[m+1];
	for(int i = 1; i <= m; ++i) cin >> fa[i];
	cin >> k;
	int* num = new int[k+1];
	for(int i = 1; i <= k; ++i) cin >> num[i];
	for(int i = 1; i<= m; ++i){
		for(int j = 1; j <= k; ++j){
			if(fa[i] == num[j]){
				best[i][j] = max(best[i][j-1], best[i-1][j], best[i-1][j-1]) + 1;
			}
			else best[i][j] = max(best[i][j-1], best[i-1][j], best[i-1][j-1]);
		}
	}
	cout << best[m][k] << endl;
	return 0;
} 
