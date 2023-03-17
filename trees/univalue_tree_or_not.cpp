#include <iostream>



int main(int argc, char** argv) {
	 int val = root->val;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            root = st.top();
            st.pop();
            if(root->val != val) return false;
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
        }
        return true;
}
