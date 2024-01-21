//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
  void solve(int i , vector<int>&arr, int n , set<vector<int>>&st){
      if(i ==  n){
          st.insert(arr);
          return ;
      }
      for(int j =i;j<n;j++){
          swap(arr[i] , arr[j]);
          solve(i+1 , arr , n , st);
          swap(arr[i] , arr[j]);
      }
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>>st;
        vector<int>temp;
        solve(0 ,arr , n ,st);
        vector<vector<int>>ans;
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends