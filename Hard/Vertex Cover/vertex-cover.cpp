//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
int solve(vector<pair<int,int>> &edges, vector<int> &vis, int i, int m) {
    if (i == m) {
        return 0;
    }
    int u = edges[i].first;
    int v = edges[i].second;
    if (!vis[u] && !vis[v]) {
        vis[u] = true;
        int firstNode = 1 + solve(edges, vis, i + 1, m);
        vis[u] = false;
        vis[v] = true;
        int secondNode = 1 + solve(edges, vis, i + 1, m);
        vis[v] = false;
        return min(firstNode, secondNode);
    }
    return solve(edges, vis, i + 1, m);
}
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            vector<int> vis(n+1,0);
            return solve(edges,vis,0,edges.size());
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends