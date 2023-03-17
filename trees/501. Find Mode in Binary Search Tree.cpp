#include <iostream>
#include<vector>
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

vector<int>p;
int current=0,freq=0,maxfreq=0;


vector<int> getelement(node* root)
{
	if(root==0)return p;
	getelement(root->left);
	
	if(current!=root->data)
	{
		current=root->data;
		freq=1;
	}
	
	else if(current==root->data)
	{
		freq++;
	}
	
	if(freq>maxfreq)
	{
		maxfreq=freq;
		p={current};
	}
	
	else if(freq==maxfreq)
	{
		p.push_back(current);
	}
	
	getelement(root->right);
	return p;
}
main(int argc, char** argv) {
	  node* root=0;
	  root=getnode(5);
	  root->left=getnode(2);
	  root->right=getnode(8);
	  root->right->left=getnode(7);
	  root->right->right=getnode(8);
	  p=getelement(root);
	  for(int i=0;i<p.size();i++)
	  {
	  	cout<<p[i];
	  }
}
