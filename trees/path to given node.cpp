#include <iostream>
#include<vector>
using namespace std;
class node{
	public:
		int val;
		node* left=0;
		node* right=0;
};

node* getnode(int x)
{
	node* newnode=new node();
	newnode->val=x;
	return newnode;
}


bool solve2(node* root,vector<int>&ans,int B)
 {
     if(root==0)
        return false;
        
        if(root->val==B)
        { ans.push_back(root->val);
           return true;
		}
          
           
        ans.push_back(root->val);
        if(solve2(root->left,ans,B) ||solve2(root->right,ans,B))
          return true;
       
        ans.pop_back();
        return false;
 }
 
vector<int>solve(node* A, int B) {
    vector<int>ans;
   if(A==0)
     return {};
     solve2(A,ans,B);
   return ans;
}


int main(int argc, char** argv) {
	node* root=0;
	root=getnode(1);
	root->left=getnode(2);
	root->left->left=getnode(4);
	root->left->right=getnode(5);
	root->right=getnode(3);
	root->right->left=getnode(6);
	root->right->right=getnode(6);
	 vector<int>ans=solve(root,5);
	 for(int i=0;i<ans.size();i++)
	 {
	 	cout<<ans[i]<<" ";
	 }
}
