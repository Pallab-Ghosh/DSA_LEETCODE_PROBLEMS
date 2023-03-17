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
void insert_at_mid(int x)
{
	node* slow=head;
	node* first=head;
	node* p=0;
	while(first!=0)
	{
		p=slow;
		slow=slow->next;
		first=first->next->next;
	}
  node* newnode=getnode(x);
  newnode->next=p->next;
  p->next=newnode;
	
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
    insert_at_mid(100);
      display();
}
