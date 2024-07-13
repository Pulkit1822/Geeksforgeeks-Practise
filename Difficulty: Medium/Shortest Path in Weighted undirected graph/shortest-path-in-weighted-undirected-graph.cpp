//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:edges){
            int weight = i[2];
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        vector<int> distance(n+1,INT_MAX);
        vector<int> parent(n+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        distance[1] = 0;
        parent[1] = 0;
        q.push({0,1});
        
        
        while(!q.empty()){
            int cur = q.top().second;
            int d = q.top().first;
            q.pop();
            
            for(auto k: adj[cur]){
                int neighbour = k.first;
                int weight = k.second;
                
                if(d + weight < distance[neighbour]){
                    distance[neighbour] = d + weight;
                    parent[neighbour] = cur;
                    q.push({distance[neighbour],neighbour});
                }
            }
        }
        
        if(distance[n] == INT_MAX) return {-1};
        
        vector<int> ans;
        int temp = n;
        while(temp != 0){
            ans.push_back(temp);
            temp = parent[temp];
        }
        ans.push_back(distance[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends