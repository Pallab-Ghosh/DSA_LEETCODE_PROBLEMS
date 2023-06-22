#include <iostream>
#include<vector>
using namespace std;


    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size()<k)
        return 0; 
        
        int ans=0,temp=0,i=0,j=0,c=0;
        while(j<arr.size())
        {
            temp+=arr[j];
            if(j-i+1<k)
            {
                j++;
            }
            else
            {
               ans=temp/k;
               if(ans>=threshold)
                {
                    c++;
                }
               temp-=arr[i];
               i++;
               j++;
            }
        }
        return c;
    }
int main(int argc, char** argv) {
  vector<int>arr={2,2,2,2,5,5,5,8};
  int k=3,threshold=4;
  cout<<numOfSubarrays(arr,k,threshold);
  
}
