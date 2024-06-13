//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    const int M=1e9+7;
    int padovanSequence(int n)
    {
       //code here
       int p[n];
       p[0]=1;
       p[1]=1;
       p[2]=1;
       for(int i=3;i<=n;i++){
           p[i] = (p[i-3] + p[i-2])%M;
       }
       return (p[n])%M;
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
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends