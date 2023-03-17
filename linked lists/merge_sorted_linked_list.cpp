 
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

node* head1=0;
node* head2=0;



void display(node* head)
{
	node* temp=head;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

node* merge_sorted_list(node* head1,node* head2)
{
	if(head1==0)
	{
		return head2;
	}
	
	
	if(head2==0)
	{
		return head1;
	}
	
	node* p= new node();
	node* q=p;
	while(head1!=0 and head2!=0)
	{
		
		if(head1->data<=head2->data)
		{
			p->next=head1;
			p=p->next;
			head1=head1->next;
		}
		else
		{
			p->next=head2;
			p=p->next;
			head2=head2->next;
		}
	}
	

	
	while(head1!=0)
	{
	     p->next=head1;
	     p=p->next;
	    head1=head1->next;
	}
	
	while(head2!=0)
	{
		p->next=head2;
		p=p->next;
		head2=head2->next;
	}
	
	
	return q->next;
}

int main(int argc, char** argv) {
        head1=getnode(1);
        head1->next=getnode(2);
        head1->next->next=getnode(3);
        display(head1);
        
        
        head2=getnode(1);
        head2->next=getnode(3);
        head2->next->next=getnode(4);
        cout<<endl;
        display(head2);
        cout<<endl;
        
        node* p=merge_sorted_list(head1,head2);
        display(p);
        
}
