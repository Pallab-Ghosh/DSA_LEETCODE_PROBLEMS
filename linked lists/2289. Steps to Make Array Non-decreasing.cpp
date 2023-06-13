#include <iostream>
#include<vector>
#include<stack>
using namespace std;

int steps(vector<int>v)
{
	int n=v.size();
	int ans=0,cnt;
	stack<pair<int,int>>s;
	s.push({v[n-1],0});
	for(int i=n-2;i>=0;i--)
	{
		cnt=0;
		while(!s.empty() and v[i]>s.top().first)
		{
			cnt=max(cnt+1,s.top().second);
			s.pop();
		}
		ans=max(ans,cnt);
		s.push({v[i],cnt});
	}
	return ans;
}
int main(int argc, char** argv) {
	vector<int>v{5,3,4,4,7,3,6,11,8,5,11};
	cout<<steps(v);
}
