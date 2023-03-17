#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

   bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    
        void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList) {
        if (start >= s.length()) 
            result.push_back(currentList);
            
        for (int end = start; end < s.length(); end++)
           {
            if (isPalindrome(s, start, end)) 
            {
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList);
                currentList.pop_back();
            }
        }
    }

    
 vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList);
        return result;
    }
    
    

 
int main(int argc, char** argv) {
	string s="aab";
	vector<vector<string>>v=partition(s);
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
