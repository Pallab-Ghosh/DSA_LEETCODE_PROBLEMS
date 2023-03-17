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
	cout<<endl;
}

node* add_two_number(node* root1,node* root2)
{
	if(root1==0)return root2;
	if(root2==0)return root1;
	
	int carry=0;
	int sum=0;
	node* p=new node();
	node* q=p;
	while(root1!=0 and root2!=0)
	{
        sum=root1->data+root2->data;
        sum+=carry;
        sum=sum%10;
        carry=sum/10;
        p->next=getnode(sum);
        p=p->next;
        root1=root1->next;
        root2=root2->next;
	}

	
	if(carry==1)
	{
		p->next=getnode(carry);
		p=p->next;
	}
	cout<<q->next;
}

int main(int argc, char** argv) {
     node* root=0;
     root=getnode(2);
     root->next=getnode(4);
     root->next->next=getnode(3);
     display(root);
     
     node* root2=0;
     root2=getnode(5);
     root2->next=getnode(6);
     root2->next->next=getnode(4);
     display(root2);
     
    node* p=add_two_number(root,root2);
     display(p);
     

}
