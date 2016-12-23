#include<iostream>
#include<vector>
using namespace std;
struct tree{
	int bode;
	tree* left;
	tree* right;
};
tree* buildtree(int* end,int* middle,int n){
	if(n==0) return NULL;
	tree *node=new tree;
	int j,k;
	node->bode=end[n-1];
	for(j=0;j!=n;++j){
		if(middle[j]==end[n-1]) break;
	}
	node->left=buildtree(end,middle,j);
	node->right=buildtree(end+j,middle+j+1,n-j-1);
	return node;
}

void print(tree* node){
	vector<tree*> v1;
	int rear=0,front=0;
	v1.push_back(node);
	rear++;
	while(rear!=front){
		if(front==0) cout<<v1[front]->bode;
		else cout<<" "<<v1[front]->bode;
		if(v1[front]->left!=NULL){
			v1.push_back(v1[front]->left);
			rear++;
		}
		if(v1[front]->right!=NULL){
			v1.push_back(v1[front]->right);
			rear++;
		}
		front++; 	
	}
	cout<<endl;
	return;
}
int main(){
	int n;
	cin>>n;
	int *end=new int[n],*middle=new int[n];
	tree *node;
	for(int i=0;i!=n;++i) cin>>end[i];
	for(int i=0;i!=n;++i) cin>>middle[i];
	node=buildtree(end,middle,n);
	print(node);
	delete[]end;
	delete[]middle;
	return 0;
} 
