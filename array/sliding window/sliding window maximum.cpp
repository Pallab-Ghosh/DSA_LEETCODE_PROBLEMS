#include <iostream>
#include<string.h>
#include<unordered_set>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
 vector<int>ans;

void maxSlidingWindow(vector<int>& nums, int k)
    {
        
         deque<int>temp;
         int i=0,j=0;
         
         while(j<nums.size())
         {
         	while(!temp.empty() and temp.front()<nums[j])
         	{
         		temp.pop_back();
			}
			
			temp.push_back(nums[j]);
			if(j-i+1<k)
			{
				j++;
			}
			
			else
			{
				ans.push_back(temp.front());
				if(temp.front()==nums[i])
				{
					temp.pop_front();
				}
				i++;
				j++;
			}
		 }
		 
    }
    
    
int main(int argc, char** argv) {
	vector<int>v = {1,3,-1,-3,5,3,6,7};
	int k = 3;
	maxSlidingWindow(v,k);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
