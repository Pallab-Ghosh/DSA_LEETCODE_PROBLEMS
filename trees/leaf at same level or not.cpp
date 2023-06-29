 #include <iostream>
 #include<queue>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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



bool check(node* root)
{
	int ans=0;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		int size=q.size();
		while(size--)
		{
			node* p=q.front();
			q.pop();
			if(p->left)
			 q.push(p->left);
			 
			 if(p->right)
			 q.push(p->right);
			 
			 if(p->left==0 and p->right==0)
			 ans=1;
		}
		if(ans and !q.empty())
		  return false;
	}
	return true;
}
int main(int argc, char** argv) {
	node* root=0;
	root=getnode(10);
	root->left=getnode(20);
	root->right=getnode(30);
	root->left->left=getnode(10);
	root->left->right=getnode(15);
	
   if(check(root))
	{
		cout<<"leaf at same level";
	}
	else
	{
		cout<<"not";
	}
}
