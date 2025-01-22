 class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin() , nums.end());
        long long start = 0 , end = 0 , ans = INT_MIN , sum = 0;

        while(end < nums.size())
        {
           sum = sum + nums[end];

           while(nums[end] * (end-start+1) - sum > k)
           {
             sum = sum - nums[start];
             start++;
           }
           ans = max(ans , end-start+1);
           end++;
        }
        return ans;
    }
};