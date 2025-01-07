#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int start = 0 , end = 0 , sum=0;
        int res = INT_MIN;
        unordered_map<int,int>mp;

        while(end < nums.size())
        {
            sum = sum + nums[end];
            mp[nums[end]]++;

            while (mp[nums[end]] > 1)
            {

                 sum = sum - nums[start];
                 mp[nums[start]]--;
                 start++;
            }

            res = max(res , sum);
            end++;
        }
        return res;

    }
};
int main(int argc, char** argv) {
	return 0;
}
