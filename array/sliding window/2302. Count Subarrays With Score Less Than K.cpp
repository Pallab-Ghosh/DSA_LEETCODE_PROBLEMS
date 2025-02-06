class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long end = 0 , start = 0 , score = 0 , res = 0;

        while(end < nums.size())
        {
            score = score + nums[end];

            while( score * (end-start+1) >= k)
            {
                score = score - nums[start]--;
                start++;
            }

            if(score*(end-start+1) < k)
            {
                res = res + (end-start+1);
            }
            end++;
        }
        return res;
    }
};
