#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j,int& flag)
 {
            
        if(i<0 || j<0 || i>n-1 || j>m-1 || grid2[i][j]==0 || grid2[i][j]==2) return;

            grid2[i][j]=2;

            if(grid1[i][j] == 0)
            {
                flag = 0;
            }
            
            
            dfs(grid1, grid2, i+1, j,flag);
            dfs(grid1, grid2, i-1, j,flag);
            dfs(grid1, grid2, i, j+1,flag);
            dfs(grid1, grid2, i, j-1,flag);
        }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int ans=0;
        n=grid2.size();
        m=grid2[0].size();

   
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int flag=1;
                if(grid2[i][j]==1 && grid2[i][j]==grid1[i][j])
                {
                    dfs(grid1,grid2,i,j,flag);
                    ans+=flag;
                }
            }
        }
        return ans;
    }
    

int main(int argc, char** argv) {
	return 0;
}
