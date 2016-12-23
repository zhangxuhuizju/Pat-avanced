#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int check[10000]={0};
int isPrime(int n){
	if(n == 2) return 1;
	for(int i = 2; i <= sqrt(n); ++i){
		if(n%i == 0) return 0;
	}
	return 1;
}
int main(){
	int n, id, flag, num;
	vector<int> v;
	scanf("%d",&n);
	for(int i = 0 ; i != n; ++i){
		scanf("%d",&num);
		v.push_back(num);
	}
	scanf("%d",&n);
	auto k = v.begin();
	for(int i = 0 ; i != n; ++i){
		scanf("%d",&num);
		if(!check[num]){	
			k = find(v.begin(), v.end(), num);
			if(k == v.end()) printf("%.4d: Are you kidding?\n",num);
			else{
				check[num] = 1;
				flag = k - v.begin() + 1;
				if(flag == 1) printf("%.4d: Mystery Award\n",num);
				else if(isPrime(flag)) printf("%.4d: Minion\n",num);
				else printf("%.4d: Chocolate\n",num);
			}
		}else printf("%.4d: Checked\n",num);
	}
}
