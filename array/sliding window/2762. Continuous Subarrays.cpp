#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        map<int,int>mp;
        int start = 0 , end = 0 ;
        long long ans = 0;

        while(end < nums.size())
        {
            mp[nums[end]]++;

            while(abs(mp.rbegin()->first - mp.begin()->first > 2))
            {
                mp[nums[start]]--;
                if(mp[nums[start]] == 0)
                  mp.erase(nums[start]);

                start++;
            }
            ans = ans + (end-start+1);
            end++;
        }
        return ans;
    }
};
int main(int argc, char** argv) {
	return 0;
}
