#include <iostream>
#include<vector>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==j)
                {
                    sum+=mat[i][j];
                    mat[i][j]=0;
                }
            }
        }
        int i=0,j=m-1;
          while(i<n and j>=0)
          {
             sum+=mat[i][j];
             j--;
             i++;
          }
        return sum;
    }

int main(int argc, char** argv) {
   vector<vector<int>>v={{1,2,3},{4,5,6},{7,8,9}};
   cout<<diagonalSum(v);
}
