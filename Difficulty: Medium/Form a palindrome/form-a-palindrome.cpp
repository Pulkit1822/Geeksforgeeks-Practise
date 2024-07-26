//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    string str2=str;
    reverse(str2.begin(),str2.end());
    int n=str.size();
    int dp[n+1][n+1];
    memset(dp, 0,sizeof(dp));
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(str[i-1]==str2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            
        }
    }
    return abs(dp[n][n]-n);
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends