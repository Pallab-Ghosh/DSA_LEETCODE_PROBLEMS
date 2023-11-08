#include <iostream>
#include<vector>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector<vector<int>>insert(vector<vector<int>>intervals, vector<int>newIntervals)
{
	vector<vector<int>>ans;
	
	for(auto temp:intervals)
	{
		if(temp[1] < newIntervals[0])
		{
			ans.push_back(temp);
		}
		
		else if(newIntervals[1] < temp[0])
		{
			ans.push_back(newIntervals);
			newIntervals=temp;
		}
		else
		{
			newIntervals[0]=min(temp[0],newIntervals[0]);
			newIntervals[1]=max(temp[1],newIntervals[1]);
		}
	}
	
	ans.push_back(newIntervals);
	return ans;
}

int main(int argc, char** argv) {
	vector<vector<int>>intervals={{1,2},{3,5},{6,7},{8,10},{12,16}};
	vector<int>newIntervals={{4,8}};
	vector<vector<int>>ans=insert(intervals,newIntervals);
	
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
