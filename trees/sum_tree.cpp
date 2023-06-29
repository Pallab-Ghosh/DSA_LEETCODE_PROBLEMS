#include <iostream>
 int sum(struct Node *root)
   {
    if (root == NULL)
        return 0;
     
    return sum(root->left) + root->data +
           sum(root->right);
   }
 
 
    bool isSumTree(Node* root)
    {
          int ls, rs;
 
    // If node is NULL or it's a leaf
    // node then return true
    if (root == NULL ||
       (root->left == NULL &&
        root->right == NULL))
        return 1;
 
   // Get sum of nodes in left and
   // right subtrees
   ls = sum(root->left);
   rs = sum(root->right);
 
   // If the node and both of its
   // children satisfy the property
   // return 1 else 0
    if ((root->data == ls + rs) &&
          isSumTree(root->left) &&
          isSumTree(root->right))
        return 1;
 
   return 0;
    }

int main(int argc, char** argv) {
	return 0;
}
