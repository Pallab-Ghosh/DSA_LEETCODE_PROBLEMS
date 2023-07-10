#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
        vector<pair<int,int>>vp;
        for(int i=0; i<n; i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(), vp.end());

        int i = 0, j = n-1;

        while(i < j)
        {
            int sum = vp[i].first + vp[j].first;
            if(sum == target) 
            return {vp[i].second,vp[j].second};

            if(sum < target)
             i++;

            else
               j--;
        }
        return {};  //o(nlogn)
    }

int main(int argc, char** argv) {
	vector<int>v={7,2,15,11};
	vector<int>ans=twoSum(v,9);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	
}
