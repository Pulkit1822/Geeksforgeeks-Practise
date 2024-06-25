//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int FindCoverage(vector<vector<int>>&matrix){
        int left,right,top, bottom,sum=0;
        for(int i=0; i<matrix.size(); i++){
                top=0;
                bottom=0;
            for(int j=0; j<matrix[0].size(); j++){
                right=0;
                left=0;
                if(matrix[i][j]==0){
                    if(i>0) top=matrix[i-1][j];
                    if(i<matrix.size()-1) bottom=matrix[i+1][j];
                    if(j>0) left=matrix[i][j-1];
                    if(j<matrix[0].size()-1) right=matrix[i][j+1];
                    sum+=(left+right+top+bottom);
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		Solution obj;
		int ans = obj.FindCoverage(matrix);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends