//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(int index,int k,vector<int> &arr,int n,set<vector<int>> &ans,vector<int> &tmp){
        if(k == 0){
            ans.insert(tmp);
            return;
        }
        
        if(index >= n){
            return;
        }
        
        solve(index + 1,k,arr,n,ans,tmp);
        
        if(arr[index] <= k){
            tmp.push_back(arr[index]);
            solve(index + 1,k - arr[index],arr,n,ans,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(),arr.end());
        set<vector<int>> ans;
        vector<int> tmp;
        
        solve(0,k,arr,n,ans,tmp);
        
        vector<vector<int>> v(ans.begin(),ans.end());
        
        return v;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends