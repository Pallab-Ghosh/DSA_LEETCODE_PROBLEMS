 class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long ans = 0 ;

        int start = 0 , end = 0 , min_ind = -1 , max_ind = -1;


        while( end < nums.size() )
        {
            if(nums[end] < minK || nums[end] > maxK )//means culprit / start
            {
                start = end+1;
                min_ind = -1;
                max_ind = -1;
                
            }

            if(nums[end] == minK)
            {
                min_ind = end;
            }
             

            if(nums[end] == maxK)
            {
                max_ind = end;
            }
             

            //long long smaller_ind = min(min_ind , max_ind);

             if(min_ind != -1 && max_ind != -1)
             {
                 ans += (min(min_ind , max_ind) - start + 1);
             }
            
        end++;

        }

        return ans;
    }
};




 
