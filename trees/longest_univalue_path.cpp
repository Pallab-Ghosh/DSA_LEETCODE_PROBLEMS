#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
};

node* getnode(int x)
{
	node* newnode=new node();
	newnode->data=x;
	newnode->left=0;
	newnode->right=0;
	return newnode;
}

int dfs(node* root,int &res)
{
	if(root==0)return 0;
	int l=dfs(root->left,res);
	int r=dfs(root->right,res);
	int left=(root->left && root->data==root->left->data)?l+1:0;
	int right=(root->right && root->data==root->right->data)?r+1:0;
	res=max(res,left+right);
	return max(left,right);
}

int longest_univalue_path(node* root)
{
	if(root==0)return 0;
	int res=0;
	dfs(root,res);
	return res;
}

int main(int argc, char** argv) {
	node* root=0;
	root=getnode(5);
	root->left=getnode(4);
	root->left->left=getnode(1);
	root->left->right=getnode(1);
	root->right=getnode(5);
	root->right->right=getnode(5);
	int x=longest_univalue_path(root);
	cout<<x;
}
