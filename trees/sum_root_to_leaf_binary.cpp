#include <iostream>
#include<vector>
#include<math.h>
#include<cstring>
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

void preorder(node* root)
{
	if(root==0)return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


int binarytoInteger(vector<int>bin)
{
        int ans = 0;
        int size = bin.size()-1;
        for(int i = 0 ; i < bin.size() ; i++){
            if(bin[i] == 1)
			{
            ans=pow(2,size);
            }
            
            size--;
        }
        return ans;
}

void solve(node* root , vector<int> path , int &sum){
        //base case
        if(root == NULL)
            return;
        
        path.push_back(root->data);
        
        if(root->left == NULL && root->right == NULL){
            int x = binarytoInteger(path);
            sum += x;
        }
        
        solve(root->left , path , sum);
        solve(root->right , path , sum);
        
        path.pop_back();
    }
    
    
int main(int argc, char** argv) {
	node* root=0;
	root=getnode(2);
	root->left=getnode(4);
	root->left->left=getnode(8);
	root->left->right=getnode(10);
	root->right=getnode(6);
	root->right->left=getnode(12);
	root->right->right=getnode(20);
	preorder(root);
	cout<<endl;
	int sum=0;
	vector<int> path;
    solve(root , path , sum);
	cout<<sum;
}
