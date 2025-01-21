 
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k)
     {
        sort(nums.begin(), nums.end());
        long long sum = 0; 
        long long left = 0;      
       long long maxFreq = 0;    

    for (int right = 0; right < nums.size(); ++right)
     {
        sum += nums[right];

        while ( (long long)(nums[right] * (right - left + 1)) - sum  > k)
        {
            sum -= nums[left]; 
            left++;
        }
        maxFreq = max(maxFreq, right - left + 1);
    }

    return maxFreq;
}
};
 