#include<cstdio>
using namespace std;
int ascii[256] = {0};
int main(){
	char a[10001];
	char b[10001];
	gets(a);
	gets(b);
	for(int i = 0; b[i] != '\0'; ++i){
		ascii[b[i]-'0'] = 1;
	}
	
	
	//aaaaa 
	for(int i = 0; a[i] != '\0'; ++i){
		if(!ascii[a[i] - '0']) printf("%c",a[i]);
	}
	printf("\n");
	return 0;
} 
