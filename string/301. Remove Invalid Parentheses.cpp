#include <iostream>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;

vector<string>ans;
unordered_map<string,int>mp;


int  getMinInValid(string s)
    {
 
	   stack<char> stck;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(')
                stck.push(s[i]);
                
            else if(s[i] == ')')
            {
                if(stck.size() > 0 && stck.top() == '(')
                    stck.pop();
                    
                else
                    stck.push(s[i]);
            }
            i++;
        }
        return stck.size();
    }
    
    
    void solve(string s,int inv_paren)
    {
    	if(mp[s]!=0)
    	  {
    	  	return;
		  }
    	
    	if(mp[s]==0)
    	{
    		mp[s]++;
		}
    	  
    	if(inv_paren<0)
    	  return ;
    	  
    	if(inv_paren==0)
    	{
    		if(!getMinInValid(s))
    		{
    			  ans.push_back(s);
			}
    		return;
		}
		
		for(int i=0; i<s.size(); i++)
        {
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right, inv_paren-1);
        }
        
        return;
	}
    
    
  vector<string>removeInvalidParentheses(string s)
    {
    	int inv_paren=getMinInValid(s);
    	cout<<inv_paren<<endl;
    	solve(s,inv_paren);
    	return ans;
	}
    
int main(int argc, char** argv) {
	string s="))((";
	
	vector<string>temp=removeInvalidParentheses(s);
	
	for(int i=0;i<temp.size();i++)
	{
		cout<<temp[i]<<endl;
	}
}
