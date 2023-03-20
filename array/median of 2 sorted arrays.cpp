#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int>v;
	int count=0;
	float mid=0;
	float sum=0;
	for(auto i:nums1)
	{
		v.push_back(i);
	}
	
	for(auto j:nums2)
	{
		v.push_back(j);
	}
	
	for(auto i:v)
	{
		count++;
	}
	sort(v.begin(),v.end());
	int n=v.size();
	int start=0;
	int end=n-1;
	
	mid=start+(end-start)/2;
	if(count%2==1)
	{
		return v[mid];
	}
	
	else if(count%2==0)
	{
		sum=(float)(v[mid]+v[mid+1])/2;
		return sum;
	}
	return {};
}



int main(int argc, char** argv) {
	vector<int>v1={1,2};
	vector<int>v2={3,4};
	cout<<findMedianSortedArrays(v1,v2);
}
