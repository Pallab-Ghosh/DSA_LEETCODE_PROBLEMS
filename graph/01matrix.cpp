#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
             int m = mat.size(), n = mat[0].size();

	    vector<vector<bool>>vis(m,vector<bool>(n));
	    vector<vector<int>>dist(m,vector<int>(n));  

	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(mat[i][j] == 0){
	                q.push({{i,j},0});
	                vis[i][j] = true;
	            }
	        }
	    }

	    vector<int>offset = {0,1,0,-1,0};

	    while(!q.empty()){
	        int i = q.front().first.first;
	        int j = q.front().first.second;
	        int dis = q.front().second;

	        q.pop();
	        dist[i][j] = dis;

	        for(int k=0;k<4;k++){
	            int r = i + offset[k];
	            int c = j + offset[k+1];
	            if(r>=0 && r<m && c>=0 && c<n && !vis[r][c]){
	                q.push({{r,c},dis+1});
	                vis[r][c] = true;
	            }
	        }
	    }
        
	    return dist;
    }

int main(int argc, char** argv) {
	return 0;
}
