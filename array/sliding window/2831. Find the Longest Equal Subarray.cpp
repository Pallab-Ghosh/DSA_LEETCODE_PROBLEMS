class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int end = 0 , start = 0 , maximum_freq = 0 , res=0;

        unordered_map<int,int>mp;

        while(end < nums.size())
        {
            mp[nums[end]]++;
            
            maximum_freq = max(maximum_freq , mp[nums[end]]);

            while((end-start+1) - maximum_freq > k)
            {
                mp[nums[start]]--;
                start++;
                if(mp[nums[start]] == 0)
                  mp.erase(nums[start]);
            }
            res = max(res , maximum_freq);
            end++;
        }
        return maximum_freq;
    }
};
