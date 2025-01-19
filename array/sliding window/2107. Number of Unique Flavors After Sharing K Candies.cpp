#include <iostream>
#include<unordered_map>
#include<vector>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int shareCandies(vector<int>& nums, int k) {
	
	if(k==0) return nums.size();
	unordered_map<int,int>mp;
	int start =0 , end=0 , res=0 , ele_map=0;
	
	for(int i : nums)
	  mp[i]++;
	  
	  
	
	while(end < nums.size())
	{
		int end_ele = nums[end];
		mp[end_ele]--;
		
		if(mp[end_ele] ==0)
		  mp.erase(end_ele);
		  
		if(end - start +1 < k)
		   end++;
		   
		 else if(end-start+1 == k)
		 {
		 	res = max(res , (int)mp.size());
		 	mp[nums[start]]++;
		 	start++;
		 	end++;
		 } 
	}
	return res;
}
 
int main(int argc, char** argv) {
	 
	 vector<int>v ={2,2,2,2,3,3};//1,2,2,3,4,3 k=3 op=3, 1,2,2,3,4,4,5 k=3 op=4 ,  [2,2,2,2,3,3], k = 2 op=2
	 int k = 2;                     //[2,4,5], k = 0 op=3
	 cout<<shareCandies(v, k) ;
}
