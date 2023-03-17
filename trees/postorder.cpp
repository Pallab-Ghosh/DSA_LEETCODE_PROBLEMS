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

void postorder(node* root)
{
	if(root==0)return ;
     
     postorder(root->left);
     postorder(root->right);
	 cout<<root->data<<" ";
}
int main(int argc, char** argv) {
	node* root=0;
	root=getnode(2);
	root->left=getnode(4);
	root->left->left=getnode(8);
	root->left->right=getnode(10);
	root->right=getnode(6);
	root->right->left=getnode(12);
	root->right->right=getnode(20);
	postorder(root);

}
