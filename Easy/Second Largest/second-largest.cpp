//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:	
	int print2largest(int arr[], int n) {
	    int ans = -1;
	    for(int i=0; i<n; i++)
    {
        if(arr[i] > ans)
        {
            ans = arr[i];
        }
    }
    
    int second = -1;
    for(int i=0; i<n; i++)
    {
        if(ans!=arr[i])
        {
            second = max(second , arr[i]);
        }
    }
    return second;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends