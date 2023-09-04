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

    long long  Mod=1e9+7;
    long long totalSum =0, ans=0;
    
long long dfs(node* root)
{
	if(root==0)return 0;
	long long sum=root->data+dfs(root->left)+dfs(root->right);
	ans=max(ans,(totalSum-sum)*sum);
	return sum;
}
    
  int maxProduct(node* root)
  {
  	 totalSum=dfs(root);
  	 dfs(root);
  	 return ans%Mod;
  }
  
  
int main(int argc, char** argv) {
  node* root=0;
  root=getnode(1);
  root->left=getnode(2);
  root->left->left=getnode(4);
  root->left->right=getnode(5);
  root->right=getnode(3);
  root->right->left=getnode(6);
  cout<<maxProduct(root);
}
