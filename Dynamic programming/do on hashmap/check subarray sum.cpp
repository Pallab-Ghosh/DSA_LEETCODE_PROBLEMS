#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

  bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum%k)==mp.end())
            {
                mp[sum%k]=i+1;
            }
            else if(mp[sum%k]<i)
            {
                 return true;
            }
        }
        return false;
    }
int main(int argc, char** argv) {
	vector<int>v{23,2,4,6,7};
	int k=6;
	if(checkSubarraySum(v,k))
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}
