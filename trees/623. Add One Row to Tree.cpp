#include <iostream>

  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         queue<TreeNode*>q;
        TreeNode *newnode=new TreeNode(val);
        if(depth==1){
            newnode->left=root;
            return newnode;
            }
        q.push(root);
        int currentlevel=2;
        while(!q.empty()){
            int qsize=q.size();

            if(currentlevel==depth){
               for(int i=0;i<qsize;i++){
                   TreeNode *currentnode=q.front();
                    TreeNode *newnode1=new TreeNode(val);
                   TreeNode *newnode2=new TreeNode(val);
                   q.pop();
                   if(currentnode->left)
                       newnode1->left=currentnode->left;
                   if(currentnode->right)
                       newnode2->right=currentnode->right;
                   currentnode->left=newnode1;
                   currentnode->right=newnode2;
               } 
                break;
            }
            
            for(int i=0;i<qsize;i++){
                TreeNode *cn=q.front();
                q.pop();
                if(cn->left)
                    q.push(cn->left);
                if(cn->right)
                    q.push(cn->right);
                
            }
            currentlevel++;
        }
        return root;
    }

int main(int argc, char** argv) {
	return 0;
}
