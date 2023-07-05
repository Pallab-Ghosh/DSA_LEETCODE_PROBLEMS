#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int findPlatform( vector<int>arr,  vector<int>dep,int n)
{
	int ans=1,i=1,j=0;
	sort(arr.begin(),arr.end());        // time o(nlogn)+o(n)   space o(1)
	sort(dep.begin(),dep.end());
	int plt=1;
	while(i<n and j<n)
	{
		if(arr[i]<=dep[j])
		{
			plt++;
			i++;
		}
		else if(arr[i]>dep[j])
		{
			plt--;
			j++;
		}
		ans=max(ans,plt);
	}
	return ans;
}
int main(int argc, char** argv) {
   vector<int>arrival={900,945,955,1100,1500,1800};
   vector<int>departure={920,1200,1130,1150,1900,2000};
   cout<<findPlatform(arrival,departure,arrival.size());
}
