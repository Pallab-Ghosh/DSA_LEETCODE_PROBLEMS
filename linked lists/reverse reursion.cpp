
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
node* head=0;
node* tail=0;

void insert(int x)
{
	node* newnode=getnode(x);
    newnode->next=head;
    head=newnode;
}

void display()
{
	node* temp=head;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

node* reverse(node* head)
{
	
if(head->next==0)
{
	return head;
}

node* p=reverse(head->next);
head->next->next=head;
head->next=0;
return p;

}

int main(int argc, char** argv) {
     insert(10);
     insert(20);
     insert(30);
     insert(40);
     insert(50);
     insert(60);
     insert(70);
     insert(80);
     display();
     cout<<endl;
     head=reverse(head);
     display();
}
