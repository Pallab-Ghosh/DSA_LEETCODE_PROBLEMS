#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
  int maxMeetings(	vector<int>start, 	vector<int>end, int n)
    {
        int v=-1;
        int ans=0;
        vector<pair<int,int>>meet;
        for(int i=0;i<n;i++)
        {
            meet.push_back({end[i],start[i]});
        }
        sort(meet.begin(),meet.end());
        
        for(int i=0;i<n;i++)
        {
            if(meet[i].second>v)
            {
                ans++;
                v=meet[i].first;
            }
             
        }
        return ans;
    }

int main(int argc, char** argv) {
	vector<int>start={1,3,0,5,8,5};
	vector<int>end={2,4,6,7,9,9};
	int n=start.size();
	cout<<maxMeetings(start,end,n);
}
