#include <iostream>
#include<vector>
using namespace std;


vector<vector<int>>construct2DArray(vector<int>v,int m,int n)
{
	int k=0;
	if(m*n!=v.size())
	{
	return {};
	}
	
	vector<vector<int>>ans(m,vector<int>(n));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans[i][j]=v[k];
			k++;
		}
	}

	return ans;
}
int main(int argc, char** argv) {
	vector<int>v={1,2,3,4};
	vector<vector<int>>ans=construct2DArray(v,2,2);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
