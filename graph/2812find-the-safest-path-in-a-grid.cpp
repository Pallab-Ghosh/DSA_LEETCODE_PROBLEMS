#include <iostream>
#include<queue>
#include<vector>

using namespace std;
	vector<int>dir_i={-1,0,1,0};
	vector<int>dir_j={0,1,0,-1};
	
	
	bool is_path(vector<vector<int>>&factor_array,int factor)
	{
		vector<vector<bool>>vis(factor_array.size(),vector<bool>(factor_array.size(),false));
		if(factor_array[0][0]<factor)
		{
			return false;
		}
		
		queue<pair<int,int>>q;
		q.push({0,0});
		vis[0][0]=true;
		
		while(!q.empty())
		{
			auto node=q.front();
			q.pop();
			int start_i=node.first;
			int start_j=node.second;
			
			if(start_i==factor_array.size()-1 && start_j==factor_array[0].size()-1 )
			return true;
			
			for(int i=0;i<4;i++)
			{
				int new_i=start_i+dir_i[i];
				int new_j=start_j+dir_j[i];
				
				if(new_i>=0 && new_i<factor_array.size()&&new_j>=0 && new_j<factor_array[0].size())
				{
					if(!vis[new_i][new_j] && factor_array[new_i][new_j]>=factor)
				      {
				  	    vis[new_i][new_j]=true;
					    q.push({new_i,new_j});
				      }
				}
				
			}
		}
		return false;
	}
	
	
int get_safeness_factor(vector<vector<int>>& grid,vector<vector<int>>&factor_array)
{
	queue<pair<int,int>>q;
	vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
	
	for(int i=0;i<grid.size();i++)
	{
		for(int j=0;j<grid[0].size();j++)
		{
		
					if(grid[i][j]==1)
					{
						q.push({i,j});
						vis[i][j]=true;
					}
		}
	}
	
	
	
	int curr_factor=0;
	
	while(!q.empty())
	{
		int size=q.size();
		for(int i=0;i<size;i++)
		{
				auto start=q.front();
				int start_i=start.first;
				int start_j=start.second;
				q.pop();
		        
				factor_array[start_i][start_j]=curr_factor;
				
				for(int i=0;i<4;i++)
				{
					int new_i=start_i+dir_i[i];
					int new_j=start_j+dir_j[i];
					
					if(new_i>=0 && new_i<grid.size() && new_j>=0 && new_j<grid[0].size())
					{
						if(!vis[new_i][new_j])
						{
							vis[new_i][new_j]=true;
							q.push({new_i,new_j});
						}
					}
				
				}
		}

	   curr_factor++;
		
	}
	return curr_factor;
	
}

  int maximumSafenessFactor(vector<vector<int>>& grid)
    {
    
        vector<vector<int>>factor_array(grid.size(),vector<int>(grid[0].size(),-1));
        	
        int max_factor=get_safeness_factor(grid,factor_array);
        cout<<"max_factor"<< max_factor<<endl;
        
        int start=0;
        int end=max_factor;
        int ans;
        while(start<=end)
        {
        	int mid=(start+end)/2;
        	if(is_path(factor_array,mid))     //o(n^2 + n^2*log(max_factor))
        	{
        		ans=mid;
        		start=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
        return ans;
    }
    
int main(int argc, char** argv)
 {
	
    vector<vector<int>>grid={{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};   
    cout<<maximumSafenessFactor(grid);

}
