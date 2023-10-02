#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

  void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int& curr){
        queue<pair<int,int>> q;
        q.push({i,j});
        curr+= grid[i][j];
        vis[i][j]=1;
        int dx[]= {1,-1,0,0};
        int dy[]= {0,0,-1,1};
        while (!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            for (int it=0; it<4; it++){
                int nr= x+dx[it];
                int nc= y+dy[it];
                if (nc>=0 && nc<grid[0].size() && nr>=0 && nr<grid.size() && !vis[nr][nc] && grid[nr][nc]>0)
				{
                    q.push({nr,nc});
                    curr+= grid[nr][nc];
                    vis[nr][nc]=1;
                }
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (!vis[i][j] && grid[i][j]>0){
                    int curr=0;
                    bfs(grid,vis,i,j,curr);
                    ans= max(ans,curr);
                }
            }
        }
        return ans;
    }

int main(int argc, char** argv) {
	return 0;
}
