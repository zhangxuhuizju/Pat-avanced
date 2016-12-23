#include<iostream>
#include<math.h>
using namespace std;
int numChange(int n,int d){
	int sum = 0,mod;
	while(n != 0){
		mod = n % d;
		sum = sum * d + mod;
		n = n / d;
	}
	return sum;
}
int isPrime(int num){
	if(num <= 1) return 0;
	if(num == 2) return 1;
	for(int i=2;i<=sqrt(num);++i){
		if(num % i == 0) return 0;
	}
	return 1;
}
int main(){
	int n,d,num;
	cin>>n;
	while(n>=0){
		cin>>d;
		num=numChange(n,d);
		if(isPrime(num)&&isPrime(n)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		cin>>n;
	}
	return 0;
}
