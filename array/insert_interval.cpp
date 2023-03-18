#include <iostream>
#include<vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


vector<vector<int>>insert_interval(vector<vector<int>>&v,vector<int>p)
{
	vector<vector<int>>ans;
	for(auto temp:v)
	{
		if(temp[1]<p[0])
		{
			ans.push_back(temp);
		}
		else if(p[1] <temp[0])
		{
			ans.push_back(p);
			p=temp;
		}
		else
		{
			p[0]=min(p[0],temp[0]);
			p[1]=max(p[1],temp[1]);
		}
	}
	ans.push_back(p);
	return ans;
}
int main(int argc, char** argv) {
	vector<vector<int>>v={
	{1,2},
	{3,5},
	{6,7},
	{8,10},
	{12,16}
	};
	vector<int>p{4,8};
	vector<vector<int>>ans=insert_interval(v,p);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
