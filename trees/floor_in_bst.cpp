#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
};

node* getnode(int x)
{
	node* newnode=new node();
	newnode->data=x;
	newnode->left=0;
	newnode->right=0;
	return newnode;
}

int floor(node* root, int x)
{
   if (root == NULL) return -1;

    // Your code here
    node* answer =NULL;
    // answer = newNode(INT_MAX);
    
    while(root!=NULL){
        if(root->data > x ){
            root = root->left;
        }
        else if(root->data<=x){
            answer = root;
            root=root->right;
        }
    }
    if(answer==NULL){
            return -1;
        }
    return answer->data;
}


int main(int argc, char** argv) {
	node* root=0;
	root=getnode(8);
	root->left=getnode(4);
	root->right=getnode(12);
	
	root->left->left=getnode(2);
	root->left->right=getnode(6);
	root->right->left=getnode(10);
	root->right->right=getnode(14);


	cout<<endl;

	cout<<"ans is "<<floor(root,5);

}
