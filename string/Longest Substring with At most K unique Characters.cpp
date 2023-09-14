#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void call (string s,int i,int j)
{
	cout<<i<<" ---- "<<j<<endl;
	for(int start=i;start<=j;start++)
	{
		cout<<s[start]<<" ";
	}
	cout<<endl;
}
int longestKSubstr(string s,int k)
{
     if(s.size()<k)
     return -1;
     
	unordered_map<char,int>mp;
	int ans=INT_MIN;
	int i=0,j=0;
	
	while(j<s.size())
	{
	    mp[s[j]]++;
	    
	    if(mp.size()<k)
	    {
	    	j++;
		}
		
		else if(mp.size()==k)
		{
			ans=max(ans,j-i+1);
			j++;
		
		}
		
		else if(mp.size()>k)
		{
			while(mp.size()>k)
			{
				char out=s[i];
				mp[out]--;
				
				if(mp[out]==0)
				{
					mp.erase(out);
				}
				i++;
			}
			j++;
		}
	}
	
   return mp.size()==k? ans: -1;

}
int main(int argc, char** argv) {
   string s="aaaa";
   int k=2;
   cout<<longestKSubstr(s,k);
}
