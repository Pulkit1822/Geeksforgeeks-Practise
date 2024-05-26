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
    vector<vector<int>> dp;
    int f(vector<int> &v, int i, int p){
        if(i == v.size()){
            return 0;
        }
        if(dp[i][p+1] != -1) return dp[i][p+1];
        int nt = f(v,i+1,p);
        int t = 0;
        if(p == -1 || abs(v[i]-v[p]) == 1) t = 1+f(v,i+1,i);
        return dp[i][p+1] = max(nt, t);
    }
    int longestSubseq(int n, vector<int> &a) {
        dp.resize(n, vector<int>(n+1, -1));
        return f(a,0,-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends