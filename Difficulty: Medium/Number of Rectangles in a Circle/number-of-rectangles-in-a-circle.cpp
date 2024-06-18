//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int ans=0;
        for(int i=1;i<(2*r);i++){
            for(int j=1;j<(2*r);j++){
                float val=sqrt(i*i + j*j);
                float d= (2*r) *1.0;
                if(val <= d){
                    ans++;
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
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends