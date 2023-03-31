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
	return newnode;
}

void preorder(node* root)
{
	if(root==0)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

bool binary_heap(node* root)
{
	queue<node*>q;
	bool is_heap=false;
	q.push(root);
	while(!q.empty())
	{
		node* p=q.front();
		q.pop();
		if(p->left)
		{
			if(is_heap||p->left->data>p->data)
			  return false;
			  
			  q.push(p->left);
		}
		else
		{
			is_heap=true;
		}
		
		if(p->right)
		{
			if(is_heap||p->right->data>p->data)
			  return false;
			  
			  q.push(p->right);
		}
		else
		{
			is_heap=true;
		}
	}
	return is_heap;
}

int main(int argc, char** argv) {
	node* root=0;
	root=getnode(97);
	root->left=getnode(46);
	root->right=getnode(37);
	root->left->left=getnode(12);
	root->left->left->left=getnode(6);
	root->left->left->right=getnode(9);
	root->left->right=getnode(3);
	root->left->right->left=getnode(2);
	root->left->right->right=getnode(4);
	root->right->left=getnode(7);
	root->right->right=getnode(1);
	preorder(root);
	if(binary_heap(root))
	{
		cout<<"it is heap";
	}
	else
	{
		cout<<"no its not heap";
	}
}
