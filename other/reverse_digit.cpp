#include <iostream>
#include<vector>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int reverse(int x)
{
	int ans=0, pm=1;
	vector<int>v;
	
	if(x<0)
	{
		pm=-1;
		x*=pm;
	}
	
	if(x==INT_MIN || x==INT_MAX)
	return 0;
	while(x>0)
	{
		v.push_back(x%10);
		x=x/10;
	}
	
	for(int i=0;i<v.size();i++)
	{
		if(ans>INT_MAX/10)return 0;
		ans=ans*10;
		ans=ans+v[i];
	}
	ans*=pm;
	return ans;
}
int main(int argc, char** argv) {
	int x=-123; //x=1534236469 op will 0 dont alow big num in this problem
	cout<<reverse(x);
}
