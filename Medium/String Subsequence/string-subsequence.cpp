//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
private:
    int func(int ind, string s1, string s2, int s1_ind, int s2_ind, vector<vector<int>>& dp) {
        if (s2_ind == s2.size()) {
            return 1;
        }
        
        if (ind == s1.size()) {
            return 0;
        }
        
        if (dp[ind][s2_ind] != -1)
            return dp[ind][s2_ind];
        
        int take = 0, notTake = 0;
        if (s1[ind] == s2[s2_ind]) {
            take = func(ind + 1, s1, s2, ind + 1, s2_ind + 1, dp);
        }
        notTake = func(ind + 1, s1, s2, ind + 1, s2_ind, dp);
        
        return dp[ind][s2_ind] = (take + notTake) % 1000000007;
    }
public:
    int countWays(string s1, string s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return func(0, s1, s2, 0, 0, dp);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends