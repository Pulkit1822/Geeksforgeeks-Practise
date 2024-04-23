//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
   int mod=1e9+7;
   int fun(int x,int y,vector<vector<int>>&dp){
       if (x==0 && y==0)return 1;
       
      if (x<0 || y<0)return 0;
      if (dp[x][y]!=-1)return dp[x][y];
      int left=fun(x,y-1,dp);
      int right=fun(x-1,y,dp);
      return dp[x][y]=(left+right)%mod;
   }
    int ways(int x, int y)
    {
        int n=max(x,y);
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       
       return fun(x,y,dp)%mod;
      
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends