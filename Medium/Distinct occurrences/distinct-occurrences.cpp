//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

/*You are required to complete this method*/

class Solution
{
    public:
    int mod = 1e9+7;
    int f(int m , int n,string &s, string &t,vector<vector<int>> &dp){
       if(n < 0){
            return 1;
        }
        if(m < 0){
            return 0;
        }
         
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        if(s[m] == t[n]){
           
            return dp[m][n] = (f(m-1,n,s,t,dp)%mod+f(m-1,n-1,s,t,dp)%mod)%mod;
        }
        return dp[m][n] = f(m-1,n,s,t,dp)%mod;
    }
    int subsequenceCount(string S, string T)
    {
        
      int m = S.size();
      int n = T.size();
      vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
      return f(m-1,n-1,S,T,dp);
    }
};
 
 



//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends