#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
  TreeNode* trimBST(TreeNode* root, int low, int high) {
          if(!root) return nullptr;
        
        if(root->val < low) {
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }

int main(int argc, char** argv) {
	return 0;
}
