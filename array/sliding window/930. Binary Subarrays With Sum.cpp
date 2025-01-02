#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
      /* unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end()) {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays; */



        int cum_sum = 0 , prefix_zero = 0 , res = 0;

        int start = 0 , end = 0 ;

        while(end < nums.size())
        {
            cum_sum = cum_sum + nums[end];

            while( (start < end)  && (nums[start] == 0 || cum_sum > goal) )
            {

                if(nums[start] == 0)
                  prefix_zero++;

                 else 
                  prefix_zero = 0;

                 cum_sum = cum_sum - nums[start];
                 start++;
            }

            if(cum_sum == goal)
            {
                res = res + prefix_zero + 1 ;
            }

            end++;
        }
        return res;
    }
};

int main(int argc, char** argv) {
	return 0;
}
