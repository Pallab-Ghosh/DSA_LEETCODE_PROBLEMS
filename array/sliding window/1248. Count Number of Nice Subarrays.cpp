#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

      /*
        unordered_map<int , int>mp;
        int end = 0 , start=0 , res=0;

        while(end < nums.size())
        {
            int get_off = (nums[end] % 2);
            if( get_off != 0)
            {
                mp[nums[end]]++;
                
            }


            while(mp[get_off] == k)
            {
                res = res+1;
                int del_no = nums[start];

                mp[del_no]--;

                if(mp[del_no]==0)
                  mp.erase(nums[start]);

                start++;
            }
            end++;

        }

        return res;
        */

         int ansCnt = 0; // Final count of subarrays
        int cnt = 0;    // Count of valid subarrays ending at current position
        int i = 0, j = 0; // Two pointers for the sliding window

        while (j < nums.size()) {
            if (nums[j] % 2 != 0) { // If the current element is odd
                k--; // Decrement k as we have encountered an odd number
                cnt = 0; // Reset the count of valid subarrays ending at this position
            }
            
            while (k == 0) { // While we have exactly k odd numbers in the window
                if (nums[i] % 2 != 0) { // If the leftmost element of the window is odd
                    k++; // Increment k as we will remove this odd number
                }
                cnt++; // Increment count of valid subarrays ending at current position
                i++; // Move the left pointer of the window to the right
            }
            
            ansCnt += cnt; // Add the count of valid subarrays to the final answer
            j++; // Move the right pointer of the window to the right
        }

        return ansCnt; // Return the final count of subarrays with exactly k odd numbers
    
    }
};
int main(int argc, char** argv) {
	return 0;
}
