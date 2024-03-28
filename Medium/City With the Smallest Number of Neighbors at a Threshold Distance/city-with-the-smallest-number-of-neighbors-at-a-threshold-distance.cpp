//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++
#define ii pair<int, int>
#define ff first 
#define ss second
#define mp make_pair

const int inf = 2e9;

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int k) {
        // Your code here
        vector<vector<ii>> g(n);
        for(auto v: edges){
            g[v[0]].push_back(mp(v[1], v[2]));
            g[v[1]].push_back(mp(v[0], v[2]));
        }
        
        auto dijkestra = [&](int source, vector<int> &dist) -> void{
            dist = vector<int>(n, inf);
            set<ii> st;
            st.insert(mp(0, source));
            while(!st.empty()){
                auto d = (st.begin())->ff, nn = (st.begin())->ss;
                st.erase(st.begin());
                if(d > dist[nn]) continue;
                dist[nn] = d;
                for(auto A: g[nn]){
                    auto neigh = A.ff, wt = A.ss;
                    if(d + wt < dist[neigh])
                        st.insert(mp(d + wt, neigh));
                }
            }
        };
        
        int ans = -1, num = 1e9;
        vector<int> dist;
        for(int i = 0; i < n; ++i){
            dijkestra(i, dist);
            int c = 0;
            for(auto d: dist) c += (d <= k);
            if(num > c){
                ans = i, num = c;
            }
            else if(num == c){
                ans = max(ans, i);
            }
            else continue;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends