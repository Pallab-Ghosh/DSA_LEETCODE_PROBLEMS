#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;



int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        if(nums.size()==0)return 0;
        int ans=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }

        for(auto it:s)
        {
            if(s.find(it-1)==s.end())
            {
                count=1;
                int x=it;
                while(s.find(x+1)!=s.end())
                {
                    x=x+1;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
int main(int argc, char** argv) {
	vector<int>arr={0,3,7,2,5,8,4,6,0,1};
    cout<<longestConsecutive(arr);
}
