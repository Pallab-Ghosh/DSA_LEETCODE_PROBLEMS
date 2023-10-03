#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
   vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
 sort(nums1.begin(),nums1.end());
  sort(nums2.begin(),nums2.end());//Time complexity:O(nlogn + mlogm)  Space complexity:O(1)




        int i=0, j=0;
        int m=nums1.size()-1, n=nums2.size()-1;
        vector<int> ans;

        while(i<=m && j<=n){

            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;

            }else if(nums1[i]<nums2[j]){
                i++;

            }
            else{
                j++;
            }
            ans.erase(unique(ans.begin(), ans.end()), ans.end()); 
        }
        return ans;
    }

int main(int argc, char** argv) {
	return 0;
}
