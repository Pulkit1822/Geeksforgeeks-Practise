//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++


class disjoint_set
{
    public:
    vector<int>size;
    vector<int>parent;
    
    disjoint_set(int v)
    {
        size.resize(v+1);
        parent.resize(v+1);
        
        for(int i =0;i<=v;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    
    
    int find_parent(int u)
    {
        if(parent[u]==u)
            return u;
            
        return parent[u]=find_parent(parent[u]);
        
    }
    
    void unionBySize(int u , int v)
    {
        int ulp_u=find_parent(u);
        int ulp_v=find_parent(v);
        
        if(ulp_u==ulp_v)
        return ;
        
        if(size[ulp_u] <size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        
        else if(size[ulp_u]==size[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        
        else 
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
    
};



class Solution {
  public:
    int Solve(int n, vector<vector<int>>& grid) {
        // code here
        
        disjoint_set ds(n*n);        
        vector<vector<int>>edges;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                edges.push_back({grid[i][j],i,j});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        for(auto it:edges)
        {
            int row=it[1];
            int col=it[2];
            int w=it[0];
            
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n )
                {
                    if(grid[nrow][ncol]<=grid[row][col])
                    {
                        int node= row*n+col;
                        int adjnode=nrow*n+ncol;
                        ds.unionBySize(node,adjnode);
                    }
                }
            }
            
            if(ds.find_parent(0)==ds.find_parent(n*n-1))
                return grid[row][col];
            
        }
        
        return -1;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends