//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
         int solveTab(vector<int>&prices){
      int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int index=n-1;index>=0;index--){
           for(int buy=0;buy<=1;buy++){
               for(int limit=1;limit<=2;limit++){
                int profit=0;
               if(buy){
             int buykaro=-prices[index]+dp[index+1][0][limit];
             int skipkaro=0+dp[index+1][1][limit];
            profit=max(buykaro,skipkaro);
        }
        else{
            int sellkaro=prices[index]+dp[index+1][1][limit-1];
            int skipkaro=0+dp[index+1][0][limit];
            profit=max(sellkaro,skipkaro);
           }
            dp[index][buy][limit]=profit;
               }
           }
       }
     return dp[0][1][2];     
  }
int maxProfit(vector<int>&prices){
       return solveTab(prices);
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends