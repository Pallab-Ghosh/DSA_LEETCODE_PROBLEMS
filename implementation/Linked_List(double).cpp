#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class node{
	public:
		int data;
		node* prev=0;
		node* next=0;
};

node* get_node(int x)
{
	node* newnode = new node();
	newnode->data =x;
	return newnode;
}

void display(node* root )
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

void display2(node* tail )
{
	node* temp =tail;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
	cout<<endl;
	 cout<<"-------------------------------------------";
}

node* insert_head( int val ,node* head )
{
	 node* get_new_node = get_node(val);
	 
	 if(head == 0)
	 {
	 	head = get_new_node;
	 }
	 else
	 {
	 	get_new_node->next = head;
	 	head->prev=get_new_node;
	 	head = get_new_node;
	 }
	 return head;
}


node* insert_end( int val ,node* head  , node* tail )
{
	 node* get_new_node = get_node(val);
	 
	 if(head == 0)
	 {
	 	head = tail = get_new_node;
	    return head;
	 }
	 else
	 {
	 	tail->next = get_new_node;
	 	get_new_node->prev = tail;
	 	tail = get_new_node;
	 }
	return tail;
}

void insert_pos(int pos , int val , node* head)
{
	node* newnode=get_node(val);
	 
	 node* temp = head;
	 for(int i = 1 ; i<pos-1;i++)
	 {
	 	 temp = temp->next;
	 }
	 
	  newnode->next = temp->next;
	  newnode->next->prev=newnode;
	  newnode->prev= temp;
	  temp->next=newnode;
}

 
 node* delete_head(node* head)
 {
 	node* get_head = head;
 	cout<<"deleted node--> "<<get_head->data<<endl;
 	
 	 head = head->next;
 	 head->prev=0;
 	 delete(get_head);
 	 return head;
 }
 
 
 node* delete_end(node* head ,node* tail)
 {
 	
 	//if we not take tail variable for make list
 	 node* temp = head;
 	 while(temp->next->next!=0)
 	 {
 	 	temp = temp->next;
	 }
	 
	 node* getnode = temp->next;
	 
	 cout<<"deleted node at end "<<getnode->data<<endl;
	 
	 getnode->prev=0;
	 delete(getnode);
	 tail= temp;
	 temp->next=0;
	 return tail;
 }
 
 void delete_pos(node* head , int pos)
 {
 	node* temp = head;
 	
 	for(int i =1 ; i<pos-1;i++)
 	{
 		temp = temp->next;
	}
	
	node* get_node = temp->next;
	
	temp->next = get_node->next;
	temp->next->prev=temp;
	get_node->prev=0;
	get_node->next=0;
	cout<<"deleted data at pos 4 --> "<<get_node->data<<endl;
	delete(get_node);
	
	
 }
 
 
int main(int argc, char** argv) {
   node* head=0;
    //insert at head
    head= insert_head(1 ,  head );
    head= insert_head(100 , head );
    head= insert_head(200 , head );
    head= insert_head(300 , head );
	head= insert_head(400 , head );
	head= insert_head(500 , head );
    head= insert_head(600,  head );
    cout<<"insert head ";
	display(head);
	cout<<endl;
	 
	 //insert at tail
	node* head2=0;
	node* tail = 0;
	
	head2= tail = insert_end(1 , head2 , tail);
    tail= insert_end(100 , head2 , tail);
    tail= insert_end(200 , head2, tail );
    tail= insert_end(300 , head2 , tail);
	tail= insert_end(400 , head2 , tail);
	tail= insert_end(500 , head2, tail );
    tail= insert_end(600,  head2 , tail);
    cout<<"insert tail ";
	display(head2);
	display2(tail);
	cout<<endl;
	
	//insert at pos = 4 ,  val = 50000
	 insert_pos( 4 , 5000, head2);
	 cout<<"insert pos ";
     display(head2);
     display2(tail);
     cout<<endl;
     
     //delete_at_head
      head2 = delete_head(head2);
      cout<<"delete head ";
      display(head2);
      display2(tail);
        cout<<endl;
     
     //delete at end
      tail=delete_end(head2 , tail);
      display(head2);
      cout<<endl;
      display2(tail);
        cout<<endl;
      //delete at pos 4
      
      delete_pos(head2 , 4);
       display(head2);
      cout<<endl;
      display2(tail);
     
}
