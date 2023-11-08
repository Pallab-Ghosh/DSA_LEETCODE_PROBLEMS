#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector<vector<int>>merge(vector<vector<int>>intervals)
{
	sort(intervals.begin(),intervals.end());
	vector<int>temp=intervals[0];
	
	vector<vector<int>>ans;
	for(auto it:intervals)
	{
		if(temp[1]>=it[0])
		{
			temp[1]=max(it[1],temp[1]);
		}
		else
		{
			ans.push_back(temp);
			temp=it;
		}
	}
	ans.push_back(temp);
	return ans;
}
int main(int argc, char** argv) {
	vector<vector<int>>v={{1,3},{2,6},{8,10},{15,18}};
	vector<vector<int>>ans=merge(v);
	for(int i=0;i<ans.size();i++)
	{
	     for(int j=0;j<ans[i].size();j++)
		 {
		 	cout<<ans[i][j]<<" ";
		 }	
		 cout<<endl;
	}
}
