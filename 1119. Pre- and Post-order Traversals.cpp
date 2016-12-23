#include<iostream>
using namespace std;
struct tree{
	int body;
	tree* left;
	tree* right;
};
int judge = 0;
tree* buildTree(int* pre, int* pos, int n){
	if(n == 1){
		tree* T = new tree;
		T->body = pre[0];
		T->left = 0;
		T->right = 0;
		return T;
	}
	else if(n == 2){
		tree* T = new tree;
		T->body = pre[0];
		T->right = buildTree(pre+1, pos, 1);
		T->left = 0;
		judge = 1;
		return T;
	}
	else{
		tree* T = new tree;
		T->body = pre[0];
		int i = -1, j = -1;
		for(int k = 0; k != n; ++k){
			if(pos[k] == pre[1]){
				i = k;
				break;
			}
		}
		for(int k = 0; k != n; ++k){
			if(pre[k] == pos[n-2]){
				j = k;
				break;
			}
		}
		if(pre[1] == pos[n-2] ){
		    
			T->left = buildTree(pre+1, pos, i+1);
			T->right = 0;
	   }else{
	        T->left = buildTree(pre+1, pos, i+1);
			T->right = buildTree(pre+j, pos+i+1, n-j);
	   }
		return T;
	}	
}
int flag = 0;
void inOrder(tree* T){
	if( !T ) return;
	inOrder(T->left);
	if(!flag){
		cout << T->body;
		flag = 1;
	}else cout << " " << T->body;	
	inOrder(T->right);
}
int main(){
	int n;
	cin >> n;
	int* pre = new int[n];
	int* pos = new int[n];
	for(int i = 0; i != n; ++i) cin >> pre[i];
	for(int i = 0; i != n; ++i) cin >> pos[i];
	tree* T = buildTree(pre, pos, n);
	if(judge) cout << "No" << endl;
	else cout << "Yes" << endl;
	inOrder(T);
	cout << endl;
	delete[] pre;
	delete[] pos;
	return 0;
}
