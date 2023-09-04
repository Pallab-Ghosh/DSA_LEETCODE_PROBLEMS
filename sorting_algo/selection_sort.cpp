#include <iostream>
#include<vector>

using namespace std;
void sorting(vector<int>&v)
{
	int ind,n=v.size(),i,j;
	
	for(i=0;i<v.size()-1;i++)
	{
		ind=i;
		for(j=i+1;j<n;j++)
		{
			if(v[j]<v[ind])
			{
				ind=j;
			}
		}  //o(n^2)
		
		if(i!=ind)
		{
			swap(v[i],v[ind]);
		}
	}
}


int main(int argc, char** argv) {
  vector<int>v={64, 25, 12, 22, 11};
  sorting(v);
  for(int i=0;i<v.size();i++)
  {
  	cout<<v[i]<<" ";
  }
}
