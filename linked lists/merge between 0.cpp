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

node* merge_node(node* head)
{
	node* p=getnode(0);
	node* current=head;
	current=current->next;
	node* ans=p;
	int sum=0;
	while(current)
	{
		if(current->data==0)
		{
			ans->next=getnode(sum);
			ans=ans->next;
			sum=0;
		}
		else
		{
			sum+=current->data;
		}
		current=current->next;
	}
	return p->next;
}

int main(int argc, char** argv) {
	node* head=0;
	head=getnode(0);
	head->next=getnode(3);
	head->next->next=getnode(1);
	head->next->next->next=getnode(0);
	head->next->next->next->next=getnode(4);
	head->next->next->next->next->next=getnode(5);
	head->next->next->next->next->next->next=getnode(2);
	head->next->next->next->next->next->next->next=getnode(0);
	node* temp=head;
	
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
	cout<<endl;
	cout<<endl;
	
	temp=merge_node(head);
		while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
}
