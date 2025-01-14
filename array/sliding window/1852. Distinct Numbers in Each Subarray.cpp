#include <iostream>
#include<vector>
#include<unordered_map>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;



vector<int> func(vector<int>&v , int k)
{
	if(v.size() < k)return {};
	
	int start=0 , end=0 ;
	
	unordered_map<int,int>mp;
	
	vector<int>ans;
	
	
	while(end < v.size())
	{
		int end_ele = v[end];
		mp[end_ele]++;
		
		if(end - start +1 < k)
		  end++;
		  
		else if(end-start+1==k)
		{
			ans.push_back(mp.size());
			int delete_end_ele = v[start];
			mp[delete_end_ele]--;
			start++;
			end++;
			if(mp[delete_end_ele]==0)
			  mp.erase(delete_end_ele);
		}
		
	}
	return ans;
}

int main(int argc, char** argv) {
	vector<int>v={1,1,1,1,2,3,4};  // nums = [1,2,3,2,2,1,3], k = 3
	int k = 4;
	vector<int>ans = func(v , k);
	
	for(int i = 0 ; i<ans.size();i++)
	 cout<<ans[i]<<" ";
	
}
