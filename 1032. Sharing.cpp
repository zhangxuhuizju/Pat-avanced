#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
struct Letter{
	int next;
	char word;
}letter[100000];
int word1[100000], word2[100000];
int main(){
	int Add1, Add2, n, word1L=0, word2L=0;
	int num;
	scanf("%d %d %d", &Add1, &Add2, &n);
	for(int i = 0; i != n; ++i){
		scanf("%d", &num);
		cin >> letter[num].word >> letter[num].next;
	}
	num = Add1;
	while( num != -1 ){
		word1[word1L++] = num;
		num = letter[num].next;
	}
	num = Add2;
	while( num != -1 ){
		word2[word2L++] = num;
		num = letter[num].next;
	}
	if( word1[word1L-1] != word2[word2L-1]) printf("-1\n");
	else{
		while( word1L >= 1 && word2L >= 1 && word1[word1L-1] == word2[word2L-1]){
			--word1L;
			--word2L;
		}
		printf("%.5d\n", word1[word1L]);
	}
	return 0;
}
