//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    long long maximumAmount(int n, int arr[]) { 
        int table[n][n]; 
        for (int gap = 0; gap < n; ++gap) { 
            for (int i = 0, j = gap; j < n; ++i, ++j) { 
                int x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
                int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
                int z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
                table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
            } 
        } 
        return table[0][n - 1]; 
    } 
}; 



//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends