#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

	vector<int>ans;
	
void binary(vector <int> nums, int start, int end, int target)
{
        if(start>end)      
            return;
        
        int mid = start + (end-start)/2;   
           if(nums[mid] == target)
		   { 
            binary(nums, start, mid-1, target);
            ans.push_back(mid);
            binary(nums, mid+1, end, target);      
        }
        
        else if(nums[mid]>target)              
            binary(nums, start, mid-1, target);
            
        else                                   
            binary(nums, mid+1, end, target);
    }

void targetIndices(vector<int>& nums, int target)
 {
 	sort(nums.begin(),nums.end());
	binary(nums,0,nums.size()-1,target);
 }

int main(int argc, char** argv) {
	vector<int>v={1,2,5,2,3};

	int target=2;
	targetIndices(v,target);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
