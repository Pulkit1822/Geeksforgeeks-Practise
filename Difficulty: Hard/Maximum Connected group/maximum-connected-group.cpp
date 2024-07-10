//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    
    public :
    vector<int>rank,parent,size;
    DisjointSet(int n )
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int  i=0;i<=n;i++){
            parent[i] = i;
        }
        size.resize(n+1,1);

    }
    int findUPar(int node){
        if(node == parent[node])
            return node;
        parent[node] = findUPar(parent[node]);
        return parent[node];
    }
    void UnionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u]==rank[ulp_v]){
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++; 
        }
    }

    void UnionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] +=size[ulp_u];
        }
        else if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] +=size[ulp_v];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] +=size[ulp_v];
        }
    }
};


class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) 
    {
        
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        for(int row=0;row<n;row++)
        {
            for(int col = 0;col<m;col++)
            {
                if(grid[row][col] == 0)
                    continue;
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};
                for(int i=0;i<4;i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&grid[nrow][ncol] == 1)
                    {
                        int node = row*m+col;
                        int adjnode = nrow*m+ncol;
                        ds.UnionBySize(node,adjnode);
                        
                        
                    }
                }
            }
        }
        int ans = 0;
        for(int row = 0;row<n;row++)
        {
            for(int col =0;col<m;col++)
            {
                if(grid[row][col] == 1)
                    continue;
                set<int>st;
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};
                for(int i=0;i<4;i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&grid[nrow][ncol] == 1)
                    {
                        int adjnode = nrow*m+ncol;
                        st.insert(ds.findUPar(adjnode)); 
                        
                    }
                }
                int composize = 0;
                for(auto &it : st){
                    composize += ds.size[it]; 
                }
                ans = max(ans,composize+1);
            }
        }
        for(int i=0;i<n*m;i++)
        {
            ans = max(ans,ds.size[ds.findUPar(i)]);
        }
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
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends