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

int ceil(node* root, int tar)
{
	if(root==0)
	return -1;
	
	if(root->data==tar)
	  return root->data;
	  
	if(root->data<tar)
	{
		return ceil(root->right,tar);
	}
	
	int val=ceil(root->left,tar);
	return val>=tar?val:root->data;
}


int main(int argc, char** argv) {
	node* root=0;
	root=getnode(8);
	root->left=getnode(4);
	root->right=getnode(12);
	root->left->left=getnode(2);
	root->left->right=getnode(6);
	root->right->left=getnode(10);
	root->right->right=getnode(14);
	
	cout<<ceil(root,3);
}
