//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
     int findMinCost(string x, string y, int costX, int costY) {
        
        vector<vector<int>> dp(x.length()+1, vector<int> (y.length()+1, 0));
        
        for(int i = 1; i <= x.length(); i++){
            
            for(int j = 1; j <= y.length(); j++){
                
                if(x[i-1] == y[j-1])    dp[i][j] = dp[i-1][j-1]+1;
                
                else    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int lcs = dp[x.length()][y.length()];
        
        return (x.length()-lcs)*costX + (y.length()-lcs)*costY;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends