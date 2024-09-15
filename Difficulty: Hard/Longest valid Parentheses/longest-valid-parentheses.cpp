//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        int l=0,r=0,maxlen=0;
        int n=S.size();
        
        for(int i=0;i<n;i++)
        {
            if(S[i]=='(')
            l++;
            
            else
            r++;
            
            if(l==r)
            maxlen=max(maxlen,r+l);//2, 4
            
            if(r>l)
            r=l=0;
        }
        r=l=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(S[i]=='(')
            l++;
            
            else
            r++;
            
            if(l==r)
            maxlen=max(maxlen,r+l);
            
            if(l>r)
            r=l=0;
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends