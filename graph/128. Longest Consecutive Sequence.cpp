#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

int search(vector<int>& nums,int ele)
{
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]==ele)
		return true;
	}
	return false;
}
 int longestConsecutive(vector<int>& nums) {
 	
 	int count;
 	for(int i=0;i<nums.size();i++)
 	{
 		int ele=nums[i];
 		count=1;
 		while(search(nums,ele+1))
 		{
 			count++;
 			ele=ele+1;    //t.c---o(nxnxn)
		}
	}
	return count;
 	
 }
 
 
  int longestConsecutive_better_approach(vector<int>& nums) {
  	
  	    sort(nums.begin(),nums.end());
  	    
  	    int cnt=1,ans=0;
  	    int last_small_ele=INT_MIN;
  	    
  	    for(int i=0;i<nums.size();i++)
  	    {
  	    	if(nums[i]-1!=last_small_ele)   /// o(n x logn + n)
  	    	{
  	    		cnt=1;
  	    		last_small_ele=nums[i];
			}
			
			else if(nums[i]-1==last_small_ele)
			{
			    cnt++;
			    last_small_ele=nums[i];
			}
			
		     ans=max(ans,cnt);
			
		}
		return ans;
  }
 
 int longestConsecutive_optimal_solution(vector<int>& nums) 
 {
 	if(nums.size()==0)
 	return 0;
 	
 	unordered_set<int>s;
 	int cnt=1;
 	int ans=0;
 	
 	for(auto it:nums)
 	{
 		s.insert(it);
	}
	
  for(int i=0;i<nums.size();i++)
  {
  	 int ele=nums[i];
  	 
  	 cnt=1;
  	 
  	 if(s.find(ele-1)==s.end())
  	 {
  	 	while(s.find(ele+1)!=s.end())
  	 	{
  	 		cnt++;
  	 		ele=ele+1;
		}
	 }
	 ans=max(ans,cnt);
  }
  return ans;
  
 }

int main(int argc, char** argv) 
{
vector<int>v={102,4,100,1,101,3,2,1,1};  //   1 1 1 2 3 4 101 102
cout<<longestConsecutive(v);
cout<<endl;
cout<<longestConsecutive_better_approach(v);
cout<<endl;
cout<<longestConsecutive_optimal_solution(v);


}
