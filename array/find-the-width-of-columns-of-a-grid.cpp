#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
  vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size(),i,j;
        vector<int> ans(n);
        int y=0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                y = 0;
                if(grid[i][j]<0 || grid[i][j]==0){y++;grid[i][j]*=-1;}
                while(grid[i][j]>0){
                    y++;
                    grid[i][j] /= 10;
                }
                ans[j] = max(ans[j],y);
            }
        }
        return ans;
    }

int main(int argc, char** argv) {
	return 0;
}
