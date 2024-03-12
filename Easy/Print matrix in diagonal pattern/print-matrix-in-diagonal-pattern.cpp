//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        vector<int>ans;
        int n = mat.size();
        int j = 0;
        int up = 1;
        for(int i=0;i<n;i++)
        {
            if(up)
            {
                int t = i;
                for(int k=0;k<=j;k++)
                    ans.push_back(mat[t--][k]);
            }
            else
            {
                int t = 0;
                for(int k=j;k>=0;k--)
                    ans.push_back(mat[t++][k]);
            }
            j++;
            up = !up;
        }
        j=1;
        for(int i=1;i<n;i++)
        {
            if(up)
            {
                int t = n-1;
                for(int k=j;k<n;k++)
                    ans.push_back(mat[t--][k]);
            }
            else
            {
                int t = i;
                for(int k=n-1;k>=j;k--)
                    ans.push_back(mat[t++][k]);
                
            }
            j++;
            up = !up;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends