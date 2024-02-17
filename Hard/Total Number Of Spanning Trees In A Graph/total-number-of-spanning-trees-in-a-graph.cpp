//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
    int determinant(vector<vector<int>> matrix)
    {
        int det=0;
        if(matrix.size()==1)
            return matrix[0][0];
        else if(matrix.size()==2)
            return matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
        else
        {
            for(int p=0;p<matrix[0].size();p++)
            {
                vector<vector<int>>temp;
                for(int i=1;i<matrix.size();i++)
                {
                    vector<int>row;
                    for(int j=0;j<matrix[0].size();j++)
                    {
                        if(p!=j)
                            row.push_back(matrix[i][j]);
                    }
                    if(row.size()>0)
                        temp.push_back(row);
                }
                det=det+matrix[0][p]*pow(-1,p)*determinant(temp);
            }
            return det;
        }
    }
    
    int countSpanningTrees(vector<vector<int>>&graph, int n, int m){
        
        vector<int> degree(n, 0);
        
        vector<vector<int>> laplacianMatrix(n, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            int u = graph[i][0];
            int v = graph[i][1];
            laplacianMatrix[u][v] = -1;
            laplacianMatrix[v][u] = -1;
            
            degree[u]++;
            degree[v]++;
        }
        
        for(int i = 0; i < n; i++){
            laplacianMatrix[i][i] = degree[i];
        }
        
        vector<vector<int>> ansMatrix(n - 1, vector<int>(n - 1, 0));
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                ansMatrix[i - 1][j -1] = laplacianMatrix[i][j];
            }
        }
        
        int det = determinant(ansMatrix);
        return det;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin >> n >> m;
	    vector<vector<int>>graph(m, vector<int>(2, 0));
	    for(int i = 0 ; i < m; i++){
	        cin >> graph[i][0] >> graph[i][1];
	    }
	    Solution ob;
	    int ans = ob.countSpanningTrees(graph, n, m);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends