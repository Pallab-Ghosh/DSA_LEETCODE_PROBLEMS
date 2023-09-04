#include <iostream>

 int s=0;
 void solve(TreeNode* root)
 {
 	if(root==0)
 	return;
 	
 	if(!root->left and !root->right)
 	{
 		s+=root->data;
 		root->data=s;
 		return;
	}
	solve(root->right);
	s+=root->data;
	root->data=s;
	
	solve(root->right);
 }
    TreeNode* convertBST(TreeNode* root)
	 {
    	 if(!root)
    	 return;
    	 
    	 solve(root);
    	 return root;
    	 
	 }
int main(int argc, char** argv) {
	convertBST(root);
}
