#include<iostream>
#include<string>
using namespace std;
void print(int n){
	int h,l;
	h=n/13;
	l=n%13;
	if(h==10) cout<<"A";
	else if(h==11) cout<<"B";
	else if(h==12) cout<<"C";
	else cout<<h;
	if(l==10) cout<<"A";
	else if(l==11) cout<<"B";
	else if(l==12) cout<<"C";
	else cout<<l;
	return;
}
int main(){
	int r,g,b;
	cin>>r>>g>>b;
	cout<<"#";
	print(r);
	print(g);
	print(b);
	cout<<endl;
	return 0;
}
