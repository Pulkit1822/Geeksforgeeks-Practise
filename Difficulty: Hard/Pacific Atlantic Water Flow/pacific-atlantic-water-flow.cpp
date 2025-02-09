//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    int m,n;
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};
  public:
    
    void initialize(vector<vector<bool>>& visit, queue<vector<int>>& bfs, int r, int c){
        int i,j;
        for(i=0;i<m;i++){
            if(!visit[i][c]){
                visit[i][c]=true;
                bfs.push({i,c});
            }
        }
        for(j=0;j<n;j++){
            if(!visit[r][j]){
                visit[r][j]=true;
                bfs.push({r,j});
            }
        }
    }
    
    bool isValid(int r, int c){
        if(r<0 || c<0 || r>=m || c>=n)
            return false;
        return true;
    }
    
    void solve(vector<vector<bool>>& visit, queue<vector<int>>& bfs, vector<vector<int>> &mat){
        while(!bfs.empty()){
            auto ele = bfs.front();
            bfs.pop();
            int r = ele[0];
            int c = ele[1];
            for(int i=0;i<4;i++){
                int r1=r+x[i];
                int c1=c+y[i];
                if(isValid(r1,c1) && !visit[r1][c1] && mat[r][c]<=mat[r1][c1]){
                    visit[r1][c1]=true;
                    bfs.push({r1,c1});
                }
            }
        }
    }
    
    int countCoordinates(vector<vector<int>> &mat) {
        // code here
        m=mat.size();
        n=mat[0].size();
        vector<vector<bool>> visitP(m,vector<bool>(n,false));
        vector<vector<bool>> visitA(m,vector<bool>(n,false));
        queue<vector<int>> bfsP, bfsA;
        initialize(visitP, bfsP, 0, 0);
        initialize(visitA, bfsA, m-1, n-1);
        solve(visitP, bfsP, mat);
        solve(visitA, bfsA, mat);
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visitP[i][j] && visitA[i][j])
                    res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.countCoordinates(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends