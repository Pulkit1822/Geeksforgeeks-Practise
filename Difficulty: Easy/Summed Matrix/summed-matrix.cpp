//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
         if(q < (n+1))

      {

        long long a = q-1;

        return a;

      }

      else if(q == (n+1))

      {

        return n;

      }

      else if(q < 2*n)

      {

        long long a = 2*n-q+1;

        return a;

      }

      return 0;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends