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

void solve(node* root,vector<int>&path,int sum,int& count)
{
	if(root==0)return;
	path.push_back(root->data);
	solve(root->left,path,sum,count);
	solve(root->right,path,sum,count);
	
	int ans=0;
	for(int i=path.size()-1;i>=0;i--)
	{
		ans+=path[i];
		if(ans==sum)
		{
			count++;
		}
	}
	path.pop_back();
}
int main(int argc, char** argv) {
	node* root=0;
	root=getnode(10);
	root->left=getnode(5);
	root->left->left=getnode(3);
	root->left->left->left=getnode(3);
	root->left->right=getnode(2);
	root->left->right->right=getnode(1);
	root->right=getnode(-3);
	root->right->right=getnode(11);
	vector<int>path;
	int count=0;
	solve(root,path,8,count);
	cout<<count;
}
