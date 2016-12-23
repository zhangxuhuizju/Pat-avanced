#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct people{
	string name;
	int age;
	int worth;
}p[100000];
bool com(people a, people b){
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return a.name < b.name;
}
int main(){
	int n, m;
	cin >> n >> m;
	int* maxnum = new int[m];
	int* minage = new int[m];
	int* maxage = new int[m];
	int num = 0; 
	for(int i = 0; i != n; ++i){
		cin >> p[i].name >> p[i].age >> p[i].worth;
	}
	for(int i = 0; i != m; ++i){
		cin >> maxnum[i] >> minage[i] >> maxage[i];
	}
	sort(p, p + n, com);
	int flag = 0;
	for(int i = 0; i != m; ++i){
		cout << "Case #" << i+1 << ":" << endl;
		flag = 0;
		for(int j = 0; j != n; ++j){
			
			if(p[j].age >= minage[i] && p[j].age <= maxage[i]){
				cout << p[j].name <<" "<< p[j].age <<" "<< p[j].worth <<endl;
				++flag;
				if(flag == maxnum[i]) break;
			}
			
		}if( !flag ) cout<<"None"<<endl;
	}
	
	return 0;
}
