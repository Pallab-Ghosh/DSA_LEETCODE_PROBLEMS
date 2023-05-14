#include <iostream>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;


vector<int>next_greater(vector<int>nums1,vector<int>nums2)
{
	int n=nums2.size();
	stack<int>s;
	vector<int>ans;
	unordered_map<int,int>mp;
	for(int i=n-1;i>=0;i--)
	{
		int ele=nums2[i];
		while(!s.empty() and s.top()<=ele)
		{
			s.pop();
		}
		int res=s.empty()?-1:s.top();
		mp[ele]=res;
		s.push(ele);
	}
	
	for(auto &it:nums1)
	{
		ans.push_back(mp[it]);
	}
	return ans;
}

int main(int argc, char** argv) {
     vector<int>nums1 = {4,1,2}, nums2 = {1,3,4,2};
     vector<int>ans=next_greater(nums1,nums2);
     for(int i=0;i<ans.size();i++)
     {
     	cout<<ans[i]<<" ";
	 }
}
