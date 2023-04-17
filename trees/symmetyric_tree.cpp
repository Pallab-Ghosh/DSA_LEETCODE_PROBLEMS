#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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

bool sym(node* root1,node* root2)
{
	if(!root1 || !root2)
	    return root1==root2;
	    
	   else return root1->data==root2->data && sym(root1->left,root2->right) && sym(root1->left,root2->right);
	   
}

int main(int argc, char** argv) {
	node* root=0;
	root=getnode(1);
	root->left=getnode(2);
	root->right=getnode(2);
	root->left->left=getnode(4);
	root->left->right=getnode(3);
	root->right->left=getnode(4);
	root->right->right=getnode(3);
	if(sym(root->left,root->right))
	{
		cout<<"symmetric";
	}
	else
	{
		cout<<"not symmetric";
	}
}
