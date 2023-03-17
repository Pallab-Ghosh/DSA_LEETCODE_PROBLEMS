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

void preorder(node* root)
{
	if(root==0)return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

vector<int>temp;

int all_paths(node* root,vector<vector<int>>&v)
{
	if(root==0)return 0;
	
	   if(root)
	   {
	   	 temp.push_back(root->data);
	   }
	   int l=all_paths(root->left,v);
	   int r=all_paths(root->right,v);
	   if(l==0 and r==0)
	   {
	   	 v.push_back(temp);
	   }
	   temp.pop_back();
	   
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
	preorder(root);
	vector<vector<int>>v;
	cout<<endl;
	all_paths(root,v);
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
