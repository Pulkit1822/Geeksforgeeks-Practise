//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
    const long long int mod = 1e9+7;
  public:
    long long int findMaxProduct(vector<int>& arr) {
        long long ans = 1;
        bool flag = 0;
        int cnt = 0;
        for(auto &i:arr){
            if(i>0) {(ans*=i)%=mod; flag=1;}
            if(i<0) {cnt++;}
        }
        // cout<<cnt<<endl;
        if(flag==0 and cnt ==0) return 0;
        int mini = 1e9;
        if(cnt&1){
            for(auto &i:arr){
                if(i<0) mini = min(mini,abs(i));
            }
        }
        flag=0;
        for(auto &i:arr){
            if(i<0){
                if(abs(i) != mini) (ans*=abs(i))%=mod;
                else{
                    if(flag) (ans*=abs(i))%=mod;
                    else flag=1;
                } 
            }
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
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends