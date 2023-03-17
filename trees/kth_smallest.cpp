#include <iostream>
#include<vector>
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


void inorder(node* root,vector<int>&v)
{
	if(root==0)return ;
	inorder(root->left,v);
	v.push_back(root->data);
	inorder(root->right,v);
}
 int kthSmallest(node* root, int k) 
    {
    	vector<int>v;
        inorder(root,v);
        return v[k-1];
    }

int main(int argc, char** argv) {
	node* root=0;
	root=getnode(3);
	root->left=getnode(1);
	root->right=getnode(4);
	 root->left->right=getnode(2);
	 
	 cout<<kthSmallest(root,1);
}
