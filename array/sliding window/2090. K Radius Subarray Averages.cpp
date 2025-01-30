class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        vector<int>ans(nums.size() , -1);
        long long start = 0 , end = 0 , cum_sum = 0;

        while(end < nums.size())
        {
            cum_sum += nums[end];

            if(end - start + 1 < (2*k+1) )
               end++;

            else if(end - start + 1 == (2*k+1))
            {
                 long long  avg = cum_sum / (2*k+1);
                 long long index = (start+end)/2 ;
                 ans[index] = avg;
                 
                 cum_sum = cum_sum - nums[start];
                 start++;
                 end++;

            }
        }
        return ans;
        
    }
};
