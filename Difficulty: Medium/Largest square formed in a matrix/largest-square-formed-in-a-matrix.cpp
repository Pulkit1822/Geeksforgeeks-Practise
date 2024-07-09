//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        for(int i=0; i<m; ++i) {
            maxi = max(maxi,mat[n-1][i]);
        }
        for(int i=0; i<n; ++i) {
            maxi = max(maxi,mat[i][m-1]);
        }
        for(int i=n-2; i>=0; --i) {
            for(int j=m-2; j>=0; --j) {
                if(mat[i][j]==1) {
                    mat[i][j] = 1 + min(mat[i+1][j],min(mat[i][j+1],mat[i+1][j+1]));
                    maxi = max(maxi,mat[i][j]);
                } else {
                    mat[i][j] = 0;
                }
            }
        }
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(mat[i][j]>0)
                    mat[i][j]=1;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends