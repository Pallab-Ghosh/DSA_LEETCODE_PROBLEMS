#include <iostream>
#include<queue>
using namespace std;
class node{
	public:
		int data;
		node* left=0;
		node* right=0;
};

node* getnode(int x)
{
	node* newnode=new node();
	newnode->data=x;
	return newnode;
}

int maximum_width_tree(node* root)
{
	
	queue<pair<node*,int>>q;
	int res=1;
	q.push({root,0});
	
	while(!q.empty())
	{
		int s=q.size();
		int start=q.front().second;
		int end=q.back().second;
		res=max(res,end-start+1);
		for(int i=0;i<s;i++)
		{
			pair<node*,int>temp=q.front();
			int index=temp.second-start;
			q.pop();
			
			if(temp.first->left)
			{
				q.push({temp.first->left,2*index+1});
			}
			if(temp.first->right)
			{
				q.push({temp.first->right,2*index+2});
			}
		}
	}
	return res;
}

int main(int argc, char** argv) {
	node* root=0;
	root=getnode(1);
	root->left=getnode(3);
	root->left->left=getnode(5);
	root->left->right=getnode(3);
	root->right=getnode(2);
	root->right->right=getnode(9);
	cout<<maximum_width_tree(root);
}
