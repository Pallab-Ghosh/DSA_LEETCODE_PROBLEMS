#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* next=0;
};

node* getnode(int x)
{
	node* newnode=new node();
	newnode->data=x;
	return newnode;
}

void display(node* root)
{
	while(root!=0)
	{
		cout<<root->data<<" ";
		root=root->next;
	}
}

node* reverse(node* root,node* p)
{
	node* next=0;node* curr=root;node* prev=0;
	while(curr!=p)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}
node* reverse_k(node* root,int k)
{
	int x=k;
	node* p=root;
	while(x>0 and p)
	{
		p=p->next;
		x--;
	}
	
	if(x==0)
	{
		node* pre=0;
		pre=reverse(root,p);
		root->next=reverse_k(p, k);
		return pre;
	}
	else
	 return root;
}

int main(int argc, char** argv) {
	node* root=0;
	root=getnode(1);
	root->next=getnode(2);
	root->next->next=getnode(3);
	root->next->next->next=getnode(4);
	root->next->next->next->next=getnode(5);
	root->next->next->next->next->next=getnode(6);
	node*  p=reverse_k(root,3);
	display(p);
}
