#include <iostream>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



    void permute(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<temp.size(); i++){
            swap(temp[index] , temp[i]);
            permute(nums, ans, temp, index+1);
            swap(temp[index] , temp[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
          vector<vector<int>> ans;
        vector<int> temp = nums;
        permute(nums, ans, temp, 0);
        return ans;
    }
int main(int argc, char** argv) {
	vector<int>nums{1,2,3};
    vector<vector<int>>ans=permute(nums);
    for(int i=0;i<ans.size();i++)
    {
    	for(int j=0;j<ans[i].size();j++)
    	{
    		cout<<ans[i][j]<<" ";
    		
		}
		cout<<endl;
	}
}
