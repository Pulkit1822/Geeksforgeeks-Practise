//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
	int dp[901][901];
	int fun(int i,int ps,int n,string s){
	    if(i==n)return 1;
	    if(dp[i][ps]!=-1)return dp[i][ps];
	    dp[i][ps]=0;
	    int res=0,curr=0;
	    for(int j=i;j<n;j++){
	        curr+=(s[j]-'0');
	        if(curr>=ps)
	        res+=fun(j+1,curr,n,s);
	    }
	   return dp[i][ps]=res;
	}
	int TotalCount(string str){
	    // Code here
	    memset(dp,-1,sizeof(dp));
	    int ans=fun(0,0,str.size(),str);
	    return ans;
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends