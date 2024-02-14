//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int time;
    vector<vector<int>> ans;
    vector<int> low;
	vector<int> disc;
	vector<int> vis;
    Solution(){
        time=0;
    }
    void dfs(vector<int> adj[],int vertex,int parent){
        low[vertex]=disc[vertex]=time;
        vis[vertex]=1;
        time++;
        for(int i:adj[vertex]){
            if(!vis[i]){
                dfs(adj,i,vertex);
                low[vertex]=min(low[vertex],low[i]);
            }else if(i != parent){
                low[vertex]= min(low[vertex],low[i]);
            }
            if(low[i] > disc[vertex]){
                ans.push_back({min(vertex,i),max(vertex,i)});
            }
        }
    }
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	   low.resize(V,1e9+7);
	   disc.resize(V,1e9+7);
	   vis.resize(V,0);
	   for(int i=0; i < V; i++){
	       if(!vis[i]){
	           dfs(adj,i,-1);
	       }
	   }
	   sort(ans.begin(),ans.end());
	   return ans;
	}
};


//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends