#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        multiset<int>ms;
        
        int start = 0 , end = 0 , res = 0;

        while(end < nums.size())
        {
            ms.insert(nums[end]);

           // int diff = *ms.rbegin() - *ms.begin();

            while(*ms.rbegin() - *ms.begin() > limit)
            {
                ms.erase(ms.find(nums[start]));
                start++;
            }

            res = max(res , end-start+1);
            end++;
        }
        return res;
    }
};
int main(int argc, char** argv) {
	return 0;
}
