#include <iostream>
#include<vector>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


  int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
    	sort(begin(intervals), end(intervals));
        int ans=0;
        int n=intervals.size();
        int i=0,j=1;
        
        while(j<n)
        {
        	
        	int current_start=intervals[i][0];
        	int current_end=intervals[i][1];
        	
        	int next_start=intervals[j][0];
        	int next_end=intervals[j][1];
        	
        	//for non overlapping intervals
        	if(current_end <= next_start)
        	{
        		i=j;
        		j++;
			}
			
			//for over_lapping intervals 
			
			else if(current_end <=next_end  )
			{
				
				j++;
				ans++;
			}
			else if(current_end > next_end)
			{
				i=j;
				j++;
				ans++;
			}
		}
		return ans;
    }
int main(int argc, char** argv) {
	vector<vector<int>>intervals={{1,2},{2,3},{3,4},{1,3}};
	cout<<eraseOverlapIntervals(intervals);
}
