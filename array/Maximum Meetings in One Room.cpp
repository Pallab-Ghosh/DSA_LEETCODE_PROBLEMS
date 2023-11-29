#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 vector<int> maxMeetings(int n,vector<int> &S,vector<int> &F)
 {
 	vector<pair<pair<int,int>,int>>interval;
 	
 	for(int i=0;i<n;i++)
 	{
 		interval.push_back({{F[i],S[i]},i+1});
	 }
	 
	 vector<int>ans;
	 sort(interval.begin(),interval.end());
	 int last_inv_end=interval[0].first.first;
	 ans.push_back(interval[0].second);
	 
	 for(int i=1;i<n;i++)
	 {
	 	if(last_inv_end < interval[i].first.second)
	 	{
	 		ans.push_back(interval[i].second);
	 		last_inv_end=interval[i].first.first;
		}
	 }
	 sort(ans.begin(),ans.end());
	 return ans;
 }
 
 
int main(int argc, char** argv)
 {
	vector<int>start= {1,3,0,5,8,5},end={2,4,6,7,9,9};
	vector<int>ans=maxMeetings(start.size(),start,end);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	
 }
