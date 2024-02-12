//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution{
public:
int mod=1000000007;
    long long sequence(int n){
        if(n==1)
        return 1;
        
        long long sum=(n*(n+1))/2;
        int temp=n;
        long long totalsum=1;
        while(temp>0)
        {
             totalsum=sum*totalsum%mod;
            sum--;
            temp--;
        }
        long long ans=(totalsum+sequence(n-1))%mod;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends