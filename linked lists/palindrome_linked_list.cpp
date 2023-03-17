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

void display(node* head)
{
	node* temp=head;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

node* getmid(node* head)
{
	node* first=head;node* slow=head;
	while(first!=0 and first->next!=0)
	{
		slow=slow->next;
		first=first->next->next;
	}
  return slow;
}

node* reverse(node* head)
{
	node* prev=0;
	node* current=head;
	node* next=0;
	while(current!=0)
	{
	next=current->next;
	current->next=prev;
	prev=current;
	current=next;
	}
	cout<<prev->data<<endl;
	return prev;
}
bool palindrome(node* head)
{
	if(head==0)
	  return false;
	  
	  node* fst=head;
	  node* mid=getmid(head);
	  node* last=reverse(mid);
	  
	  
	  while(fst!=0 and last!=0)
	  {
	  	 if(fst->data!=last->data)
	  	 {
	  	 	return false;
		 }
		 fst=fst->next;
		 last=last->next;
	  }
	  return true;
}

int main(int argc, char** argv) {
	node* head=0;
	head=getnode(1);
	head->next=getnode(2);
	head->next->next=getnode(3);
	head->next->next->next=getnode(2);
	head->next->next->next->next=getnode(9);
	display(head);
	cout<<endl;
	
	if(palindrome(head))
	{
		cout<<"its palindrome";
	}
	else
	{
		cout<<"not palindrome";
	}
}
