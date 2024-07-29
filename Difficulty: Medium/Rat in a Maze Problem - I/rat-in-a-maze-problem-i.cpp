//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
private:
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& mat) {
        if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && mat[x][y] == 1) {
            return true;
        }
        return false;
    }

    void solve(vector<vector<int>>& mat, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
        // base case
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }
    
        visited[x][y] = 1;
    
        // 4 choices D,L,R,U
    
        // down
        int new_x = x + 1;
        int new_y = y;
        if (isSafe(new_x, new_y, n, visited, mat)) {
            path.push_back('D');
            solve(mat, n, ans, new_x, new_y, visited, path);
            path.pop_back();
        }
    
        // left
        new_x = x;
        new_y = y - 1;
        if (isSafe(new_x, new_y, n, visited, mat)) {
            path.push_back('L');
            solve(mat, n, ans, new_x, new_y, visited, path);
            path.pop_back();
        }
    
        // right
        new_x = x;
        new_y = y + 1;
        if (isSafe(new_x, new_y, n, visited, mat)) {
            path.push_back('R');
            solve(mat, n, ans, new_x, new_y, visited, path);
            path.pop_back();
        }
    
        // up
        new_x = x - 1;
        new_y = y;
        if (isSafe(new_x, new_y, n, visited, mat)) {
            path.push_back('U');
            solve(mat, n, ans, new_x, new_y, visited, path);
            path.pop_back();
        }
    
        visited[x][y] = 0;
    }
    
    public:
        vector<string> findPath(vector<vector<int>> &mat) {
            // Your code goes here
            int n = mat.size();
            
            vector<string> ans;
            int srcx = 0;
            int srcy = 0;
        
            if (mat[0][0] == 0) {
                return ans;
            }
        
            vector<vector<int>> visited(n, vector<int>(n, 0));
        
            string path = "";
            solve(mat, n, ans, srcx, srcy, visited, path);
            sort(ans.begin(), ans.end());
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends