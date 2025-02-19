 class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        int end = 0 , start = 0 , res = INT_MAX;
        map<int,int>mp;

        while(end < nums.size())
        {
            int end_ele = nums[end];
             

             while(end - start > indexDiff)
              {
                 int del_ele = nums[start];
                 mp[del_ele]--;
                 if(mp[del_ele] == 0)mp.erase(del_ele);
                 start++;
              }

              auto it = mp.upper_bound(end_ele) ;// get the largest ele > current;
              
              // get the result 
              if(it != mp.end())
              {

                 res = min(res , abs(it->first - end_ele)); 
              }

               //get the result which can be minimum than first one 
              if(it!=mp.begin())
              {
                   int prev_of_large_ele = prev(it)->first; // get the prev value where it points
                   res = min(res , abs(prev_of_large_ele -  end_ele));
              }
              mp[end_ele]++;
              end++;
        }
        cout<<res;

        return res <= valueDiff ? true : false;
    }
};
