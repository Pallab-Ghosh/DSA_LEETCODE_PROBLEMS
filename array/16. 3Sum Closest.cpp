#include <iostream>
#include<algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int closer=INT_MAX;
    int ans=0;
    int n=nums.size();
    if(n<3)
        return 0;

    for(int i=0;i<n-2;i++)
    {
        int j=i+1,l=n-1;
        while(j<l)
        {
            int temp=nums[i]+nums[j]+nums[l];
            if(abs(target-temp)<closer)
            {
                closer=abs(target-temp);
                ans=temp;
            }
            else if(temp < target)
                j++;
            else
                l--;
        }
        cout<<i<<" "<<j<<" "<<l<<endl;
    }
    return ans;
    }
int main(int argc, char** argv) {
	vector<int>arr={-1,2,1,-4};
	cout<<threeSumClosest(arr,1);
}
