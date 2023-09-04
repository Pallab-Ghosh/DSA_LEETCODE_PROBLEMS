#include <iostream>
#include<queue>
using namespace std;

class node{
	public:
	int val;
	node* left;
	node* right;
};

node* getnode(int x)
{
	node* newnode=new node();
	newnode->val=x;
	newnode->left=0;
	newnode->right=0;
	return newnode;
}

   int sumEvenGrandparent(node* root)
    {
  if(root==NULL)
   return 0;
   
   int sum=0;
   
   queue<node*>q;
   q.push(root);
   
   while(!q.empty())
   {
   	  int size = q.size();
   	  
   	      node* temp=q.front();
		  q.pop();
		  
		  if(temp!=NULL and (temp->val%2)==0 and temp->left!=NULL and temp->left->left!=NULL)
		  {
		     sum=sum+temp->left->left->val;	
          } 	 
          if(temp!=NULL and (temp->val%2)==0 and temp->left!=NULL and temp->left->right!=NULL)
          {
          	 sum=sum+temp->left->right->val;
		  }
   if(temp!=NULL and (temp->val%2)==0 and temp->right!=NULL and temp->right->left!=NULL)
		  {
		  	sum=sum+temp->right->left->val;
		  }
	if(temp!=NULL and (temp->val%2)==0 and temp->right!=NULL and temp->right->right!=NULL)
		  {
		  	sum=sum+temp->right->right->val;
		  }
		  
		  if(temp->left!=NULL)
		  {
		  	q.push(temp->left);
		  }
		  if(temp->right!=NULL)
		  {
		  	q.push(temp->right);
		  }
      
   }
   return sum; 
    }

int main(int argc, char** argv) 
{ 
   node* root=0;
   root=getnode(6);
   root->left=getnode(7);
   root->right=getnode(8);
    root->left->left=getnode(2);
      root->left->right=getnode(7);
       root->left->left->left=getnode(9);
        root->left->right->left=getnode(1);
         root->left->right->left=getnode(4);
         
          root->right->left=getnode(1);
            root->right->right=getnode(3);
       root->right->right->left=getnode(7);
        root->right->right->right=getnode(5);
        cout<<sumEvenGrandparent(root);
}
