#include <iostream>

int number_of_node(vector<int>v)
{
    int n=v.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum*10+v[i];
    }
    return sum;
}

  void solve(TreeNode* root,vector<int>&v ,int &sum)
  {
      if(root==0)return;
      v.push_back(root->val);
      if(root->left==0 and root->right==0)
      {
         int x=number_of_node(v);
         sum+=x;
      }
      solve(root->left,v,sum);
      solve(root->right,v,sum);
      v.pop_back();
  }



    int sumNumbers(TreeNode* root) {
        vector<int>v;
        int sum=0;
        solve(root,v,sum);
        return sum;
    }

int main(int argc, char** argv) {
	return 0;
}
