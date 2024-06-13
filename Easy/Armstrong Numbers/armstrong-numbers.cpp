//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        
        int t,arm=0;
        int duplicate=n;
        while(n>0)
         {
             t=n%10;
           arm=arm+(t*t*t);
           n=n/10;
           t=0;
       }
       if(duplicate==arm) return "Yes";
       else return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends