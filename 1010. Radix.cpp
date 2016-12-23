#include<iostream>
using namespace std;
int change(char i){
	if( i >= '0' && i <= '9' ){
		return (i - '0');
	}else return (i - 'a' + 10);
}
long long Cal(string n, long long radix){
	long long num = 0;
	for(int i = 0; i != n.length(); ++i){
		num *= radix;
		num += change(n[i]);
		if( num < 0 ) return -1;
	}
	return num;
}
int main(){
	string n1, n2, temp;
	int tag;
	long long radix, Radix, num1, num2;
	cin>>n1>>n2>>tag>>radix;
	if( tag == 2 ){
		temp = n2;
		n2 = n1;
		n1 = temp;
	}
	num1 = Cal(n1, radix);
	long long maxRadix = num1 + 1;
	long long minRadix = 0;
	for(int i = 0; i != n2.length(); ++i){
		if( change(n2[i]) > minRadix ) 
			minRadix =  change(n2[i]) + 1;
	}
	while( minRadix <= maxRadix ){
		Radix = (minRadix + maxRadix) / 2;
		num2 = Cal(n2, Radix);
		if( num2 == num1 ){
			cout<<Radix;
			return 0;
		}
		else if( num2 > num1 || num2 == -1 ){
			maxRadix = Radix - 1;
		}else if( num2 < num1 ){
			minRadix = Radix + 1;
		}
	}
	cout << "Impossible" << endl;    
    return 0;   	
}
