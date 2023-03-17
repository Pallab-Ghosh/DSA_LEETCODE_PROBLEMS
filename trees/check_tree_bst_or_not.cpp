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
	 if(root==0)return;
	 inorder(root->left,v);
	 v.push_back(root->data);
	 inorder(root->right,v);
}

  bool isValidBST(node* root) 
    {
        vector<int>v;
        inorder(root,v);
        for(int i=0;i<v.size()-1;i++)
        {
        	if(v[i+1]<=v[i])
        	{
        		return false;
			}
		}
		return true;
    }
    
int main(int argc, char** argv) {
	node* root=0;
	root=getnode(20);
	root->left=getnode(14);
	root->right=getnode(30);
	root->left->left=getnode(10);
	root->left->right=getnode(16);
	root->right->left=getnode(28);
	root->right->right=getnode(35);
	if(isValidBST(root))
	{
		cout<<"is_bst";
	}
	else
	{
		cout<<"not bst";
	}
	
}
