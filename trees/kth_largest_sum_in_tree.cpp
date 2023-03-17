#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
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

int kth_sum(node* root)
{
	if(root==0)return -1;
	queue<pair<node*,int>>q;
	q.push({root,0});
	vector<long long>v(100000,-1);
	int k=2;
	while(!q.empty())
	{
		pair<node*,int>temp=q.front();
		node* p=temp.first;
		int level=temp.second;
		q.pop();
		if(v[level]!=-1)
		{
			v[level]+=p->data;
		}
		else
		{
			v[level]=p->data;
		}
		if(p->left)
		  q.push({p->left,level+1});
		  
		  if(p->right)
		  q.push({p->right,level+1});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	return v[k-1];
}

int main(int argc, char** argv) {
	node* root=0;
	root=getnode(5);
	root->left=getnode(8);
	root->right=getnode(9);
	root->left->left=getnode(2);
	root->left->right=getnode(1);
	root->left->left->left=getnode(4);
	root->left->left->right=getnode(6);
	root->right->left=getnode(3);
	root->right->right=getnode(7);
	cout<<kth_sum(root);
}
