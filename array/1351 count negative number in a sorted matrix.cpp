#include <iostream>
#include<vector>
using namespace std;

int countNegatives(vector<vector<int>>& v)
 {
	int sum=0,n=v.size(),m=v[0].size(),j=v[0].size()-1;
	
	for(int i=0;i<n;i++)
	{
		while(j>=0 && v[i][j]<0)
		j--;
		
		if(j<0)
		sum+=m;
		
		else if(j<m)
		{
			sum+=m-j-1;
		}
	}
	return sum;
 }

int main(int argc, char** argv) {
	vector<vector<int>>v={
	 {4,3,2,-1},
	 {3,2,1,-1},
	 {1,1,-1,-2},
	 {-1,-1,-2,-3}
	};
	
	cout<<countNegatives(v);
}
