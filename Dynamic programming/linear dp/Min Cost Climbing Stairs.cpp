#include <iostream>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int minimum_cost_climbing_stairs(vector<int>&v)
{
	int n=v.size();
	for(int i=2;i<n;i++)
	{
		v[i]=v[i]+min(v[i-1],v[i-2]);
	}
	return min(v[n-1],v[n-2]);
}
int main(int argc, char** argv) {
	vector<int>v{1,100,1,1,1,100,1,1,100,1};
	cout<<minimum_cost_climbing_stairs(v);
}
