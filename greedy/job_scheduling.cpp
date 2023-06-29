#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Job{
	public:
	int id,dead,profit;
};


vector<int> JobScheduling(vector<Job>arr, int n) 
    { 
        vector<pair<int,int>> v;
        for (int i=0;i<n;i++) 
        v.push_back({arr[i].dead,arr[i].profit});
        
       sort(v.begin(),v.end());   //(4,20),(1,10),(1,40),(1,30)
       
        priority_queue<int,vector<int>,greater<int>> p;
        
        for(int i=0;i<v.size();i++)
        {
            p.push(v[i].second);
        
            if(p.size()>v[i].first)
             p.pop();
        }
                                                  
        int ans=0;
        int k=p.size();
        
        while(p.size())
        
        {
        	
            ans+=(p.top());
            p.pop();
        }
        
        return {k,ans};
    }


int main(int argc, char** argv) {
	vector<Job>v(4);
	vector<int>id={1,2,3,4};
	 vector<int>dead={4,3,1,1};
	 vector<int>profits={20,100,40,30}; 
    int n=4;
	for(int i=0;i<n;i++)
	{
		v[i].id=id[i];
		v[i].dead=dead[i];
		v[i].profit=profits[i];
	}	   
            
	vector<int>ans=JobScheduling(v,v.size());
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
