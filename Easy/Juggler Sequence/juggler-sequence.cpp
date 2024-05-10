//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        vector<int> ans(1, n);
        
        while(ans.back()>1){
            long val=ans.back();
            long sq=sqrt(val);
            long cube=sqrt(val*val*val);
            if(ans.back()&1)  ans.emplace_back(cube);
            else  ans.emplace_back(sq);
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

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends