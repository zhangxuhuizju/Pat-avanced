#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long num;
	cin >> num;
	int i = 1;
	long long front;
	long long back;
	int bit;
	long long c;
	while( num / i != 0){
		front = num / i / 10;
		back = num - (num / i) * i;
		bit = (num / i) % 10;
		if(bit == 0) c += front * i;
		else if(bit == 1){
			c += front * i;
			c += back + 1;
		}else{
			c += front*i + i;
		}
		i *= 10;
	}
	cout << c <<endl;
	return 0;
} 
