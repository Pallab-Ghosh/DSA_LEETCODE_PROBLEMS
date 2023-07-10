#include <iostream>
#include<vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

   int countNegatives(vector<vector<int>>& grid) {
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]<0)
                   c++;
            }
        }
return c;
    }
int main(int argc, char** argv) {
	vector<vector<int>>v={{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2}};
	cout<<countNegatives(v);
}
