#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class node{
	public:
		int data;
		node* next;
};

node* get_node(int x)
{
	node* newnode = new node();
	newnode->data=x;
	newnode->next=0;
	return newnode;
}

void display(node* root)
{
	node* temp = root;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
	cout<<endl;
}

node* insert_at_head(node* head , int x)
{
	if(head ==0)
	{
		 head=get_node(x);
	}
	 
	else
	{
		node* temp=get_node(x);
	    temp->next=head;
	    head=temp;
	}
	return head;
	  
}

node* newtail=0;

node* insert_at_tail( node* head  , int x)
{
	if(head==0)
	 {
	 	 head = newtail = get_node(x);
	  } 
	  else
	  {
	  	newtail->next= get_node(x);
	  	newtail = newtail->next;
	  }
	  return head;
}

void insert_at_pos(node* head , int val , int pos)
{
	//2 4 6 8 10 12 20 ---> 2 4 6 8 200 10 12 20
	
	node* temp_head = head;
	
	for(int i =1 ; i<pos-1 ;i++)
	{
		temp_head=temp_head->next;
	}
	
	if(temp_head!=0 && temp_head->next!=0)
	{
		  node* new_node = get_node(val);
		  new_node->next= temp_head->next;
		  temp_head->next=new_node;
	}
	
}

void insert_at_mid(node* head , int val)
{
	node* slow=head;
	node* fast = head;
	node* prev=0;
	while(fast !=0 and fast->next!=0)
	{
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
 
    node* newnode= get_node(val);
    newnode->next = prev->next;
    prev->next=newnode;
	
}


node* delete_at_head(node* newhead)
{
	node* gethead=newhead;
	newhead=newhead->next;
	cout<<"deleted node--->"<<gethead->data<<endl;
	delete(gethead);
	return newhead;
}

void delete_at_tail(node* newhead)
{
	node* temp = newhead;
	 while(temp!=0 and temp->next->next!=0)
	 {
	 	temp=temp->next;
	 }
	 node* deletenode= temp->next;
	 
	 cout<<"delete node --> "<<deletenode->data<<endl;
	 temp->next= 0;
	 delete(deletenode);
	 
}


void delete_at_pos(node* head , int pos)
{
	 node* getnode=0;
	 node* temp=head;
	 for(int i=1 ; i<pos-1;i++)
	 {
	 	temp=temp->next;
	 }
	 getnode = temp->next;
	 cout<<"delete node -> "<<getnode->data<<endl;
	 temp->next= getnode->next;
	 getnode->next=0;
	 delete(getnode);
}


int main(int argc, char** argv) {
	
	node* head=0;
	
	//create a  link list add value in head.
	  head = insert_at_head(head , 2);
	  head = insert_at_head(head , 4);
	  head = insert_at_head(head , 6);
	  head = insert_at_head(head , 8);
	  display(head);
    
	
	//create a  link list add value in tail.
	  node* newhead = 0;
	 // node* newtail = 0;
	
	 newhead= insert_at_tail(newhead , 2);
	 newhead= insert_at_tail(newhead , 4);
	 newhead= insert_at_tail(newhead  ,6);
	 newhead=insert_at_tail(newhead , 8);
	 newhead=insert_at_tail(newhead , 88);
	 newhead=insert_at_tail(newhead , 81);
	 newhead=insert_at_tail(newhead , 83);
	 
	 display(newhead);
	 
	 
	 //insert at position=2 value = 100 , 2 4 6 8   //new list 2 100 4 6 8
	 insert_at_pos(newhead , 200 , 2);
	 display(newhead);
	 
	 //insert at mid
	 insert_at_mid(newhead , 6777);
	 display(newhead);
	 
	 //delete at head;
	 newhead= delete_at_head(newhead);
	 display(newhead);
	 
	 ///delete at tail
	 delete_at_tail(newhead );
	 display(newhead);
	 
	 delete_at_pos(newhead,4);
	  display(newhead);
}
