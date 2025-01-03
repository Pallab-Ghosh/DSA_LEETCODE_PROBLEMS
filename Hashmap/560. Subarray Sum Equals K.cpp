#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int cum_sum =0 , res = 0 , start=0;
        mp[0]=1;

        while(start < nums.size())
        {
            cum_sum += nums[start];
             
             int prefix_sum = cum_sum - k;

             if(mp.find(prefix_sum)!= mp.end())
             {
                res = res + mp[prefix_sum];
             }

             mp[cum_sum]++; 

             start++;

            
        }
        return res;
    }
};

int main(int argc, char** argv) {
	return 0;
}
