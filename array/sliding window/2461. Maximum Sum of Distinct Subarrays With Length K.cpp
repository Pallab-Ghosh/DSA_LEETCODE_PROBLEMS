#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size() < k) return 0;

        int start = 0 , end = 0 ;
        long long cum_sum = 0 , ans=0;

        unordered_map<int,int>mp;

        while(end < nums.size())
        {
            int end_ele = nums[end];
            mp[end_ele]++;
            cum_sum = cum_sum + nums[end];


            if(end-start+1 == k )
            {
                if(mp.size() == k)
                {
                     ans = max(ans , cum_sum);
                }
                cum_sum = cum_sum - nums[start];
                mp[nums[start]]--;

                if(mp[nums[start]] == 0)
                  mp.erase(nums[start]);

                  start++;

            }
            end++;
        }
        return ans;

    }
};

int main(int argc, char** argv) {
	return 0;
}
