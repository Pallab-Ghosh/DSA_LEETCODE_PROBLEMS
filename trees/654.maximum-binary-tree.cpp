#include <iostream>
#include<vector>
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

 int search(vector<int>&nums,int left,int right)
    {
        int idx = -1;
        int val = INT_MIN;
        for(int i=left;i<=right;i++)
        {  
            if(nums[i] > val)
            {
                val = nums[i];
                idx = i;
            }
        } 
        return idx;
    }
    
    
node* tree(node* root, vector<int>& nums,int start,int end)
{
	if(start>end)
     return 0;
     
     int ind=search(nums,start,end);
     root=getnode(nums[ind]);
     root->left=tree(root->left,nums,start,ind-1);
     root->right=tree(root->right,nums,ind+1,end);
     return root;
}

node* constructMaximumBinaryTree(vector<int>v)
{
	int left=0;
	int right=v.size()-1;
	node* root=0;
	root=tree(root,v,left,right);
	return root;
}

void preorder(node* root)
{
	if(root==0)
	return ;
	
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}

int main(int argc, char** argv) {
	vector<int>v={3,2,1,6,0,5};
	node* root=constructMaximumBinaryTree(v);
	preorder(root);
}
