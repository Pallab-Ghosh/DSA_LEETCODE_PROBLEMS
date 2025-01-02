#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res=0 ; 
        int max_ele = INT_MIN;
        long long end=0 , start=0;
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++)
          {
              max_ele = max(max_ele , nums[i]); 
          }
        

        while(end < nums.size())
        {
            int no = nums[end];
            mp[no]++;

            while(mp[max_ele] >= k)
            {
                res = res + (nums.size() - end);
                int del_no = nums[start];
                mp[del_no]--;

                if(mp[del_no] == 0)
                   mp.erase(del_no);

                start++;
            }
            end++;
        }
        return res;
    }
};

int main(int argc, char** argv) {
	return 0;
}
