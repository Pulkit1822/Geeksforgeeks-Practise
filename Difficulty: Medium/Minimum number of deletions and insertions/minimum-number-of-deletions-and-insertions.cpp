//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minOperations(string str1, string str2) 
	{ 
	int m=str1.length(),n=str2.length();
	    int dp[m+1][n+1];
	    for(int i=0;i<=m;i++)dp[i][0]=0;
	      for(int i=0;i<=n;i++)dp[0][i]=0;
	      
	      for(int i=1;i<=m;i++){
	          for(int j=1;j<=n;j++){
	              if(str1[i-1]==str2[j-1]){
	                  dp[i][j]=dp[i-1][j-1]+1;
	              }else{
	                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	              }
	          }
	      }
	      
	      // value return a.length+b.length-2* lcs 
	      return m+n-2*dp[m][n];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends