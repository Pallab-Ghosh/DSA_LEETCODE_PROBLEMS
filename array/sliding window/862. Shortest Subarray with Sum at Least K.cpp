#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 


 class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        //this is whem negative eles are not there 
        /*
        int start = 0 ,end=0 , res=INT_MAX , cum_sum=0;

        while(end<nums.size())
        {
              cum_sum = cum_sum + nums[end];
              cout<<cum_sum<<endl;

              while(cum_sum >= k)
              { 
              
                 res= min(res , end-start+1); 
                  cum_sum = cum_sum - nums[start];
                  start++;
              }
           
              end++;
        }
         return res == INT_MAX?-1 : res;

        */

        deque<int>dq;
        int end=0;
        int res = INT_MAX;
        vector<long long>prefix_sum(nums.size());

        prefix_sum[0]=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        while(end < nums.size())
        {
            if( prefix_sum[end] >= k)
               res = min(res , end+1);

            while(!dq.empty() &&  prefix_sum[end] - prefix_sum[dq.front()] >= k )
              {
                  res = min(res , end - dq.front());
                  dq.pop_front();
              }

              while(!dq.empty() && prefix_sum[end] <= prefix_sum[dq.back()])
                dq.pop_back(); 


            dq.push_back(end);
             end++;
           
        }
        return res == INT_MAX ? -1 : res;
       
    }
};
