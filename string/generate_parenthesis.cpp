#include <iostream>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector<string>ans;

void sol(int left,int right,string temp)
{
	if(left<0|| right<0)
	{
		return;
	}
	if(left==0 && right==0)
	{
		ans.push_back(temp);
	}
	sol(left-1,right,temp+"(");
	if(right >left)
	{
	 sol(left,right-1,temp+")");
	}
}

 vector<string> generateParenthesis(int n)
 {
     sol(n,n," ");
     return ans;
 }
int main(int argc, char** argv) {
	 int n=3;
	 ans=generateParenthesis(n);
	 for(int i=0;i<ans.size();i++)
	 {
	 	cout<<ans[i]<<" ";
	 }
}
