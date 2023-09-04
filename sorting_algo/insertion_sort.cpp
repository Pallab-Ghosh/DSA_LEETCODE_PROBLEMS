#include <iostream>
#include<vector>
using namespace std;
 

void insertionSort(vector<int>&arr, int n)
{
    int i=1,j,targ;
    for(i=1;i<n;i++)
    {
    	targ=arr[i];
    	j=i-1;
    	while(j>=0 && arr[j]>targ)
    	{
    		arr[j+1]=arr[j];
    		j--;
		}
		arr[j+1]=targ;
	}
}
int main(int argc, char** argv) {
	vector<int>v={4,3,2,10,12,1,5,6};
	insertionSort(v,v.size());
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}
