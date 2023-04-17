#include <iostream>
#include<queue>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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

bool isCompletetree(node* root)
{
	if(root==0)return false;
	queue<node*>q;
	q.push(root);
	int p=0;
	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		if(!temp)
		{
			p=1;
			continue;
		}
		if(p and temp)
		{
			return false;
		}
		q.push(temp->left);
		q.push(temp->right);
	}
	return true;
}
int main(int argc, char** argv) {
	node* root=0;
	root=getnode(2);
	root->left=getnode(4);
	root->left->left=getnode(8);
	root->left->right=getnode(10);
	root->right=getnode(6);
	root->right->right=getnode(20);
	if(isCompletetree(root))
	{
		cout<<"its complete";
	}
	else
	{
		cout<<"not complete";
	}
}
