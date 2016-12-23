#include<iostream>
#include<string>
int main(){
	std::string word;
	std::cin>>word;
	int x,y;
	if( (word.length() + 2) % 3 == 0){
		x = y = (word.length() + 2) / 3;
	}else{
		y = (word.length() + 2) / 3 + 1;
		while( (word.length() + 2 - y) % 2 != 0){
			++y;
		}
		x = (word.length() + 2 - y) / 2;
	}
	for(int i = 0; i!= x; ++i){
		if( i!= x-1){
			std::cout<<word[i];
			for(int j = 0; j != y-2; ++j) std::cout<<" ";
			std::cout<<word[word.length()-1-i]<<std::endl;
		}else{
			for(int j = 0; j != y; ++j){
				std::cout<<word[x-1+j];
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}
