#include <iostream>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count=0;
        int ind=0;
        for(int i=0;i<mat.size();i++)
        {
            int temp=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                  temp++;
            }
           if(temp>count)
           {
               count=temp;
               ind=i;
           }
        }
        return {ind,count};
    }

int main(int argc, char** argv) {
   vector<vector<int>>v={
   {0,0,0},
   {0,1,1},
   };
   vector<int>ans=rowAndMaximumOnes(v);
   for(int i=0;i<ans.size();i++)
   {
   	cout<<ans[i]<<" ";
   }
}
