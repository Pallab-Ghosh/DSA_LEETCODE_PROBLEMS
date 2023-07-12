#include <iostream>
using namespace std;
  string smallestNumber(int S, int D){
      string ans;
      
      if((9*D)<S)
       return "-1";
       
       for(int i=D-1;i>=0;i--)
       {
           if(S>9)
           {
               ans='9'+ans;
               S=S-9;
           }
           
           else
           {
               if(i==0)
               {
                   ans=to_string(S)+ans;
               }
               
               
               else
               {
                   ans=to_string(S-1)+ans;
                   i--;
                   
                   while(i>0)
                   {
                       ans='0'+ans;
                       i--;
                   }
                   ans='1'+ans;
                   break;
               }
           }
       }
       return ans;
    }

int main(int argc, char** argv) {
	int s=20;
	int d=5;
	cout<<smallestNumber(s,d);
}
