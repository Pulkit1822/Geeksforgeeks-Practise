//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends


//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	     int hash[1001]={0};
        for(int i=0;i<n;i++)
        hash[arr[i]]++;
        for(int i=3;i<=1000;i++)
        {
            if(hash[i])
            for(int j=i+1;j<=1000;j++)
            {
                if(hash[j])
                {
                    int sum=pow(i,2)+pow(j,2);
                    int sqsum=sqrt(sum);
                    int sum1=pow(sqsum,2);
                    if(sum==sum1 && hash[sqsum])
                    {
                        return 1;
                    }
                    
                }
            }
        }
        return 0;

	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends