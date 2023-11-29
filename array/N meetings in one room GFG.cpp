#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


 int maxMeetings(vector<int>start, vector<int> end, int n)
    {
    	vector<pair<int,int>>intervals;
    	
    	for(int i=0;i<n;i++)
    	{
    		intervals.push_back({end[i],start[i]});
		}
		
		int c=1;
		sort(intervals.begin(),intervals.end());
		
		int current_interval=intervals[0].first;
		
		for(int i=1;i<n;i++)
		{
			if(current_interval < intervals[i].second)
			{
				c++;
				current_interval=intervals[i].first;
			}
		}
		return c;
	}
	
	
int main(int argc, char** argv) {
	vector<int>start= {1,3,0,5,8,5},end={2,4,6,7,9,9};
	cout<<maxMeetings(start,end,start.size());
}
