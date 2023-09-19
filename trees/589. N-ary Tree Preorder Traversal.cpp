#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 vector<int> preorder(Node* root) {
         if (!root) return ans;
        ans.push_back(root->val);
        for (auto node: root->children) preorder(node);
        return ans;
    }

int main(int argc, char** argv) {
	return 0;
}
