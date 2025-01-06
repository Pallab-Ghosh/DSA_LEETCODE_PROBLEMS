#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        int res = 0 , end = 0 , start = 0 , ans = INT_MAX;
        unordered_map<int,int>mp;

        while(end < cards.size())
        {
            mp[cards[end]]++;

            while(mp[cards[end]] == 2)
            {
                ans = min(ans,  end-start+1 );

                mp[cards[start]]--;

                if(mp[cards[start]] == 0)
                  mp.erase(cards[start]);

                  start++;
            }
            end++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
int main(int argc, char** argv) {
	return 0;
}
