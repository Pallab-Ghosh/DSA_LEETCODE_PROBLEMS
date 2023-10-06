#include <iostream>
#include<vector>
#include<queue>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) 
    { 
        int n=heights.size();
		int m=heights[0].size();
		pair<int,pair<int,int>>p;
		
		
		int diff=-1;
		vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
	    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	    pq.push({0,{0,0}});
	    dist[0][0]=0;
	    
	    
	    vector<int>dir_i={-1,0,1,0};
	    vector<int>dir_j={0,1,0,-1};
	    
	    
	    
	    while(!pq.empty())
	    {
	    	auto top_node=pq.top();
	    	pq.pop();
	    	
	    	int diff=top_node.first;
	    	int start_i=top_node.second.first;
	        int start_j=top_node.second.second;
	    	
	    	
	    	if(start_i==n-1 && start_j==m-1)
	    	return diff;
	    	
	    	for(int i=0;i<4;i++)
	    	{
	    		int new_i=start_i+dir_i[i];
	    		int new_j=start_j+dir_j[i];
	    		
	    		if(new_i>=0 && new_i<n && new_j>=0 && new_j<m)
	    		{
	    			int newEffort = max(abs(heights[start_i][start_j] - heights[new_i][new_j]), diff);
	    			
	    			if (newEffort < dist[new_i][new_j])
                    {
                        dist[new_i][new_j] = newEffort;
                        pq.push({newEffort, {new_i, new_j}});
                    }
				}
	    		
			}
		}
	     return 0; // if unreachable
    }

int main(int argc, char** argv) {
	
	vector<vector<int>>v=
	{{1,2,2},{3,8,2},{5,3,5}};
	cout<<minimumEffortPath(v);
	
}
