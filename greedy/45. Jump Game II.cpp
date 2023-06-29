#include <iostream>
#include<vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int jump2(vector<int>& nums) 
{
        int jump=0;
        int i;
        for(int i=1;i<nums.size();i++)
        {
            nums[i]=max(i+nums[i],nums[i-1]);
        }

        i=0;
        while(i<nums.size()-1)
        {
            jump++;
            i=nums[i];
        }
    return jump;
    }
int main(int argc, char** argv) {
	vector<int>v={2,3,1,1,4};
	cout<<jump2(v);
}
