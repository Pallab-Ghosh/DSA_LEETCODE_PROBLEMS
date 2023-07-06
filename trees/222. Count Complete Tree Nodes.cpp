#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
  int countNodes(TreeNode* root) {
        if(root==0)
          return 0;

        return 1+countNodes(root->left)+countNodes(root->right);
    }

int main(int argc, char** argv) {
	return 0;
}
