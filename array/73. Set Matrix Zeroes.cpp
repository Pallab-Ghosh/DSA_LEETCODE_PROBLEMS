#include <iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) 
 {
 	           int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
     {
        if (matrix[i][0] == 0)
         col0 = 0;

        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--)
     {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

        if (col0 == 0)
         matrix[i][0] = 0;
    }
    
 }

int main(int argc, char** argv) {
	vector<vector<int>>matrix={
	{0,1,2,0},{3,4,5,2},{1,3,1,5}
	};
	setZeroes(matrix);
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
