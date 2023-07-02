#include <iostream>
#include<string.h>
#include<vector>
#include<stack>
#include<Math.h>
using namespace std;
vector<string>ans;
 int perform(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    
   	
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        bool isNumber = 1;
    
        for(int i = 0; i < expression.length(); i++) 
        {
            // check if current character is an operator
            if(!isdigit(expression[i])) 
            {
                
                // if current character is not a digit then
                // exp is not purely a number
                isNumber = 0;
                
                // list of first operands
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                
                // list of second operands
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                // performing operations
          
                for(int x : left) //2*3-4*5"
                {
                    for(int y : right) 
                    {
                        int val = perform(x, y, expression[i]);
                        results.push_back(val);
                    }
                }
                
            }
        }
        
        if(isNumber == 1)
         results.push_back(stoi(expression));

        return results;
    }
int main(int argc, char** argv) {
   string s="2*3-4*5";     
    vector<int>ans=diffWaysToCompute(s);
    
    	for(int i=0;i<ans.size();i++)
    	 cout<<ans[i]<<" ";
    	 
  
}
