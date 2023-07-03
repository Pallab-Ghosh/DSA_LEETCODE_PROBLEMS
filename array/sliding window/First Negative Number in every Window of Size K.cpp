#include <iostream>
#include<deque>
#include<queue>
#include<vector>
using namespace std;

vector<int>ans;

void first_negative_no(vector<int>v,int k)
{
	deque<int>dq;
	int i=0,j=0;
	while(j<v.size())
	{
		if(v[j]<0)
		  dq.push_back(v[j]);
		  
		if(j-i+1<k)
		{
			j++;
		}
		else
		{   
		cout<<dq.front()<<endl;
			ans.push_back(dq.front());
			if(v[i]==dq.front())
			{
				dq.pop_front();
			}
			
			i++;
			j++;
		}
	}
}

int main(int argc, char** argv) 
{
   vector<int>v={12, -1, -7, 8, -15, 30, 16, 28} ;
    int  k = 3;
    first_negative_no(v,k);
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i]<<" ";
	}
}
