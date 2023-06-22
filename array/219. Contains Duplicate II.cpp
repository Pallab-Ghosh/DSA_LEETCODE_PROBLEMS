#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

  int abs(int a,int b)
  {
      return a<b ?(b-a):(a-b);
  }
  
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=i;
            }

            else
            {
                auto it=mp.find(nums[i]);
                int diff=abs(it->second,i);
                if(diff<=k)
                   return true;
                else
                  mp[nums[i]]=i;
            }
        }
        return false;
    }

int main(int argc, char** argv) {
	
	
	if(containsNearbyDuplicate(v,k))
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}
