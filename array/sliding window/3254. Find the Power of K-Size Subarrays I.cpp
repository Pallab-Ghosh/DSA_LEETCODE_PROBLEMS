 vector<int> resultsArray(vector<int>& nums, int k) {
        int count = 1;
        vector<int>ans((nums.size()-k+1), -1);
        int start =1 ,end;

        for(end = 1 ;end<k;end++)
        {
            if(nums[end] == nums[end-1]+1) 
              {
                 count++;
              }
              else 
              {
                 count= 1;
              }
        }

        if(count == k)
          ans[0]=nums[k-1];

        while(end < nums.size())
        {
            if(nums[end] == nums[end-1]+1)
            {
                count++;
            }
            else 
            {
                count = 1 ;
            }

            if(count >= k)
             {
                ans[start] = nums[end];
             }
               
            start++;
            end++;
        }
 
          return ans;
        
    }
