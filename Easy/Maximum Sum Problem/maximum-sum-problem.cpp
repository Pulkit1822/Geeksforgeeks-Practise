//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        long long solve(long long n){
        if(n==0)return 0;
        if(n==1 || n==2 || n==3 || n==4)return n;
        long long a=solve(n/2),b=solve(n/3),c=solve(n/4);
        return max(n/2,a)+max(n/3,b)+max(n/4,c);
    }
    public:
        int maxSum(int n)
        {
            long long a=solve(n);
            long long N=n;
            return max(N,a);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends