#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
};

node* getnode(int x)
{
	node* newnode=new node();
	newnode->data=x;
	newnode->next=0;
	return newnode;
}

void display(node* temp){
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

node* sum(node* root1,node* root2)
{
	if(root1==0)return root2;
	if(root2==0)return root1;
	
	int ans=0;
	int carry=0;
	node* temp=new node();
	node* p=temp;
	
	while(root1!=0 || root2!=0 || carry)
	{
		ans=0;
		if(root1!=0)
		{
			 ans+=root1->data;
		     root1=root1->next;
		}
		
		 
		if(root2!=0)
	{
			 ans+=root2->data;
		 root2=root2->next;
	}
		 
		 ans+=carry;
		 carry=ans/10;
		 node* newnode=getnode(ans%10);
		 temp->next=newnode;
		 temp=temp->next;
	}
	return p->next;
}

int main(int argc, char** argv) {
	node* root1=0;
	root1=getnode(2);
	root1->next=getnode(4);
	root1->next->next=getnode(9);
	
//	display(root1);
	
	node* root2=0;
	root2=getnode(5);
	root2->next=getnode(6);
	root2->next->next=getnode(4);
	root2->next->next->next=getnode(9);
	
	node* temp=sum(root1,root2);
	display(temp);
}
