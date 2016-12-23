#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<char> v;
	string r, w;
	getline(cin, r);
	getline(cin, w);
	transform(r.begin(), r.end(), r.begin(), ::toupper);
	transform(w.begin(), w.end(), w.begin(), ::toupper);
	int i = 0;
	int j = 0;
	auto k = v.begin();
	while(i != r.size() && j != w.size() ){
		if(r[i] == w[j]){
			++i;
			++j;
			continue;
		}else{
			k = find(v.begin(), v.end(), r[i]);
			if(k == v.end()){
				cout << r[i];
				v.push_back(r[i]);
				i++; 
			}else{
				i++;
				continue;
			}
		}
	}
	if(i != r.size()){
		for(; i != r.size(); ++i){
			k = find(v.begin(), v.end(), r[i]);
			if( k == v.end() ) cout << r[i];
		}
	}
	cout << endl;
}
