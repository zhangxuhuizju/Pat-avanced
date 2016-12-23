#include<cstdio>
int coins[100001] = {0};
int main(){
	int n, m, flag = 0;
	scanf("%d %d",&n, &m);
	int coin;
	for(int i = 0 ;i != n; ++i){
		scanf("%d", &coin);
		++coins[coin];
	}
	for(int i = 0; i != m; ++i){
		if( m - i != i && coins[i] != 0 && coins[m-i] !=0){
			printf("%d %d\n", i, m-i);
			flag = 1;
			break;
		}else if(m - i == i && coins[i] >=2){
			printf("%d %d\n", i, i);
			flag = 1;
			break;
		}
	}
	if( !flag ) printf("No Solution\n");
	return 0;
}
