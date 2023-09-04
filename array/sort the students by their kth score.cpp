#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>>&score,int k)
{

    vector<vector<int>>ans;
    vector<pair<int,int>>temp;
    int i=0;
    int n=score.size();
    
    while(i<n)
    {
    	temp.push_back(make_pair(score[i][k],i));
    	i++;
	}
	
    sort(temp.begin(),temp.end());
    
    for(int i=n-1;i>=0;i--)
    {
    	ans.push_back(score[temp[i].second]);
	}
 return ans;
}
int main(int argc, char** argv) {
	
	vector<vector<int>>arr{
	  {10,6,9,1},
	  {7,5,11,2},
	  {4,8,3,15},
	  
	   };
	vector<vector<int>>ans=rotate(arr,2);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
