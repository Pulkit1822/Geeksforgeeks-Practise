//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        int dp[w+1];
        for(int i=0;i<=w; ++i)
            dp[i]= INT_MAX;
        dp[0]=0;
        for(int i=1; i<=w;++i){
            for(int j=1; j<=i && j<=n;++j){
                if(cost[j-1]!=-1 && dp[i-j]!= INT_MAX) {
                    dp[i] = min(dp[i], cost[j-1]+ dp[i-j]);
                }
        }
        }
        return dp[w]==INT_MAX ?-1:dp[w];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends