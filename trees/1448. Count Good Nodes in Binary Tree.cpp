 #include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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

void good_nodes(node* root,int& count,int valueupto)
{
	 if(root==0)return ;
	 if(root->data>=valueupto)
	 {
	 	count++;
	 	valueupto=root->data;
	 }
	 good_nodes(root->left,count,valueupto);
	 good_nodes(root->right,count,valueupto);
}

int main(int argc, char** argv) {
	node* root=0;
	root=getnode(3);
	root->left=getnode(1);
	root->right=getnode(4);
	root->left->left=getnode(3);
	root->right->left=getnode(1);
	root->right->right=getnode(5);
     int count=0;
     int valueupto=root->data;
     good_nodes(root,count,valueupto);
     cout<<count;
}
