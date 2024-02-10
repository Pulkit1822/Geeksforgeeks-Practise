//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    
   long long dp[101][101][101];
    long long check(vector<vector<int>>&arr,int i,int j,int tar,int n)
    {
        if(i>=n || j>=n || tar<=0)return 0;
        if(i==n-1 && j==n-1){
        if(tar==arr[i][j])return 1;
         return 0;
        }
        
        if(dp[i][j][tar]!=-1)return dp[i][j][tar];
        long long take=check(arr,i+1,j,tar-arr[i][j],n)+check(arr,i,j+1,tar-arr[i][j],n);
        return dp[i][j][tar]=take;
        
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        memset(dp,-1,sizeof(dp));
        return check(arr,0,0,k,n);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends