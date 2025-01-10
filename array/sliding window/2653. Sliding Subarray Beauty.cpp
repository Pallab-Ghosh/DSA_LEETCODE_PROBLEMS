#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
         int n = nums.size(), i = 0;
        unordered_map<int, int> m;
        vector<int> ans;
        
        for(int j=0; j<n; j++) {
            m[nums[j]]++;
            if(j - i + 1 == k) {
                int cnt = x;
                for(int val=-50; val<=-1; val++) {
                    cnt -= m[val];
                    if(cnt <= 0) {
                        ans.push_back(val);
                        break;
                    }
                }
                if(cnt > 0) ans.push_back(0);
                m[nums[i++]]--;
            }
        }
        return ans;
    }
};
int main(int argc, char** argv) {
	return 0;
}
