#include <iostream>
#include<vector>
#include<queue>
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


     node* solve(vector<int>&ans,int s,int l)
     {
         if(s>l)return 0;
         int mid=(s+l)/2;
         node* root=getnode(ans[mid]);
         root->left=solve(ans,s,mid-1);
         root->right=solve(ans,mid+1,l);
         return root;
     }
     
     void level(node* root)
     {
     	queue<node*>q;
     	q.push(root);
     	while(!q.empty())
     	{
     		node* p=q.front();
     		q.pop();
     		cout<<p->data<<" ";
     		if(p->left)
     		{
     			q.push(p->left);
			 }
			 if(p->right)
			 {
			 	q.push(p->right);
			 }
		 }
	 }
int main(int argc, char** argv) {
	node* root=0;
	vector<int>v={-10,-3,0,5,9};
	root=solve(v,0,v.size()-1);
	level(root);
	
}
