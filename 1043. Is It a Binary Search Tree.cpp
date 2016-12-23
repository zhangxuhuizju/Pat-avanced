#include<iostream>
using namespace std;
struct tree{
	int body;
	tree* left;
	tree* right;
};
tree* insert(tree* T, int num){
	if( !T ){
		T = new tree;
		T->body = num;
		T->left = 0;
		T->right = 0;
	}else{
		if( num < T->body){
			T->left = insert(T->left, num);
		}else T->right = insert(T->right, num);
	}
	return T;
}
int i = 0, i_ = 0;
void preOrder(tree* T, int* pre){
 	if( !T ) return;
 	pre[i++] = T->body;
 	preOrder(T->left, pre);
 	preOrder(T->right, pre);
 }
void pre_Order(tree* T, int* pre_){
 	if( !T ) return;
 	pre_[i_++] = T->body;
 	pre_Order(T->right, pre_);
	pre_Order(T->left, pre_);
 }
void postOrder(tree* T){
 	if( !T ) return;
	postOrder(T->left);
 	postOrder(T->right);
 	if( !i ){
 		cout << T->body;
 		i = 1;
 	}else cout << " " << T->body;
 }
void post_Order(tree* T){
 	if( !T ) return;
 	post_Order(T->right);
	post_Order(T->left);
 	if( !i ){
 		cout << T->body;
 		i = 1;
 	}else cout << " " << T->body;
 }
int main(){
	int n;
	cin >> n;
	tree* T = 0;
	int* num = new int[n];
	int* pre = new int[n];
	int* pre_ = new int[n];
	for(int i = 0; i != n; ++i){
		cin >> num[i];
		T = insert(T, num[i]);
	}
	preOrder(T, pre);
	pre_Order(T, pre_);
	int flag1 = 0, flag2 = 0;
	for(int i = 0; i != n; ++i){
		if( pre[i] != num[i] ) flag1 = 1;
		if( pre_[i] != num[i] ) flag2 = 1;
		if(flag1 && flag2 ){
			cout << "NO" << endl;
			return 0;
		}
	}
	if(flag2){
		cout << "YES" << endl;
		i = 0;
		postOrder(T);
		cout << endl;
	}
	else {
		cout << "YES" << endl;
		i = 0;
		post_Order(T);
		cout << endl;
	}
	return 0;
}
