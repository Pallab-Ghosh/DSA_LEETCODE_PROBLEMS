class Solution {
public:
    int subarraySum(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>prefx_sum(n+1,0);

        for(int i=0;i<nums.size();i++)
        {
            prefx_sum[i+1] = prefx_sum[i]+nums[i];
        }
        
        
        int start = 0 ;
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            start = max(0 , i-nums[i]);

            ans = ans + (prefx_sum[i+1] - prefx_sum[start]);

        }
        return ans;
    }
};
