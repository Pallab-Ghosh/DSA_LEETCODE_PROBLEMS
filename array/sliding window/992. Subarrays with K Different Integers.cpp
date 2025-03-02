class Solution {
public:
 
   int fun(vector<int>& nums, int k)
   {
      unordered_map<int,int>mp;

      int start=0,end=0,res=0 ;

      while(end < nums.size())
      {
         int curr = nums[end];
         mp[curr]++;

         while(mp.size() > k)
         {
             int del_ch = nums[start];
             mp[del_ch]--;
             if(mp[del_ch] == 0)
               mp.erase(del_ch);

            start++;
         }

        res = res + (end-start+1); 
        end++;
      }

      return res;
   }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums , k-1);
        
      // 1 call happen  for arrays where distnct ele <=k (k=2)[count is 12 ] ,
      // 1 call happen   for arrays where distnct ele <=k(k-1=1)[count is 5 ] ,

      // so rerturn (!2-5)= 7 arrays where k=2  ditinct eles present
    
    }
};
