//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int isCircle(vector<string> &arr) {
        // code here
        int n = arr.size();
        unordered_map<char, int> start, end;
        for (int i = 0; i < n; i++) {
            start[arr[i][0]]++;
            end[arr[i].back()]++;
        }
        for (auto &i : start) {
            if (start[i.first] != end[i.first]) {
                return 0;
            }
        }
        unordered_map<char, vector<int>> graph;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            graph[arr[i][0]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 1;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            char lastChar = arr[idx].back();
            for (auto &nextIdx : graph[lastChar]) {
                if (!visited[nextIdx]) {
                    visited[nextIdx] = true;
                    q.push(nextIdx);
                    count++;
                }
            }
        }
        return count == n ? 1 : 0;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends