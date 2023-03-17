#include <iostream>
#include<unordered_map>
using namespace std;

int count_subset_sum(int arr[],int k,int n)
{
	int res=0;
	unordered_map<int,int>m;
	int currsum=0;

	 for(int i=0;i<n;i++)
	 {
	 	currsum+=arr[i];
	 	if(currsum==k)
	 	{
	 		res++;
		}
		
		if(m.find(currsum-k)!=m.end())
		{
			res+=(m[currsum-k]);
		}
		
		m[currsum]++;
	 }

	 return res;
}

int main(int argc, char** argv) {
	int arr[]={9,4,20,3,10,5};
	int k=33;
	cout<<count_subset_sum(arr,k,6);
}
