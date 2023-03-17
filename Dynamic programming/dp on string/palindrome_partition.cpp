#include <iostream>
#include<vector>
using namespace std;
void print2(vector<vector<string>> res)
{
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
   vector<vector<string>> res;
    bool ispalindrome(string &s) 
    {
        int l=0, h=s.size()-1;
        while(l<h)
        {
            if(s[l]!=s[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    
    void print(vector<string>valid)
    {
       for(int i=0;i<valid.size();i++)
       {
       	cout<<valid[i]<<" ";
	   }
	   cout<<endl;
	}

    void find(int i, string &s, string temp, vector<string>valid)
    {
        if(i==s.size())
        {
            if(temp.empty())
            {
            	res.push_back(valid);
			}
            return;
        } 

        temp += s[i];
        
        find(i+1, s, temp, valid);
        
        if(ispalindrome(temp))
        {
            valid.push_back(temp);
            
            find(i+1, s, "", valid);
        }
        
    }

int main(int argc, char** argv) {
 vector<string> valid;
 string s="aab";
    find(0, s, "", valid);
    print2(res);
    
}
