#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector<int>ans;

void binary_search(vector<int>nums,int start,int end,int target)
{
	if(start>end)
	 return ;
	 
	 int mid=(start+end)/2;
	 if(nums[mid]==target)
	 {
	 	binary_search(nums,start,mid-1,target);
	 	ans.push_back(mid);
	 	binary_search(nums,mid+1,end,target);
	 }
	 
	 else if(nums[mid] > target)
	 	binary_search(nums,start,mid-1,target);
	 	
	else 
		binary_search(nums,mid+1,end,target);
}

vector<int> targetIndices(vector<int>& nums, int target)
 {
	sort(nums.begin(),nums.end());
	int n=nums.size()-1;
	binary_search(nums,0,n,target);
	return ans;
 }

int main(int argc, char** argv) {
    vector<int>grid = {1,2,5,2,3};//1 2 2 3 5
	int target=2;
	ans=targetIndices(grid,target);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
