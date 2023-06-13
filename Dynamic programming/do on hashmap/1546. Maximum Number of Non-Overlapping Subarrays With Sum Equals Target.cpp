#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maxNonOverlapping(vector<int>& nums, int target) 
{
	unordered_map<int,int>mp;
	int c=0;
	int sum=0;
	int end=-1;
	mp[0]=-1;
	for(int i=0;i<nums.size();i++)
	{
		sum+=nums[i];
		if(mp.find(sum-target)!=mp.end()and mp[sum-target]>=end)
		{
			c++;
			end=i;
		}
		mp[sum]=i;
	}
	return c;
}



int main(int argc, char** argv) {
	vector<int>v{1,1,1,1,1};
	int target=2;
	cout<<maxNonOverlapping(v,target) ;
}
