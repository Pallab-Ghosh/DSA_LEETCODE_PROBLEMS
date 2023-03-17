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

vector<vector<int>>ans;

void path_sum(vector<int>v,node* root,int targetsum)
{
	if(root==0)return;
	v.push_back(root->data);
	targetsum-=root->data;
	if(!root->left && !root->right)
	{
		if(targetsum==0)
		{
			ans.push_back(v);
		}
	}
	else
	{
		path_sum(v,root->left,targetsum);
		path_sum(v,root->right,targetsum);
	}
	v.pop_back();
}
int main(int argc, char** argv) {
	node* root=0;
	
	root=getnode(5);
	root->left=getnode(4);
	root->left->left=getnode(11);
	root->left->left->left=getnode(7);
	root->left->left->right=getnode(2);
	root->right=getnode(8);
	
	root->right->right=getnode(4);
	root->right->right->right=getnode(1);
	root->right->left=getnode(13);
	root->right->right->left=getnode(5);
	vector<int>v;
	path_sum(v,root,22);
	
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
