//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans(2);
        int n = arr.size();
        unordered_map<int, int> hm;
        for (int i = 0; i < n; i++) {
            hm[arr[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (hm[i] == 2) {
                ans[0] = i; 
            }
            if (!hm[i]) {
                ans[1] = i; 
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends