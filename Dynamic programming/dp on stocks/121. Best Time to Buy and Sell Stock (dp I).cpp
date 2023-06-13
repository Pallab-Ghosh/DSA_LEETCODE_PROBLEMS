#include <iostream>
#include<vector>
using namespace std;

int dp_on_stocks(vector<int>v)
{
	int res=0;
	int mini=v[0];
	for(int i=1;i<v.size();i++)
	{
	    int ans=v[i]-mini;
	    res=max(res,ans);
	    mini=min(mini,v[i]);
	}
	return res;
}
int main(int argc, char** argv) {
	vector<int>v{7,1,5,3,6,4};
	cout<<dp_on_stocks(v);
}
