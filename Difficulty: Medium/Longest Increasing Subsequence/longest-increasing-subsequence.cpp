//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int dp[1001][1001];
    int solve(vector<int>& arr, int i, int p) {
        
        if(i >= arr.size()){
            return 0;
        }
        if(p != -1 && dp[i][p] != -1){
            return dp[i][p];
        }
        int taken = 0;
        if(p == -1 || arr[p] < arr[i]){
            taken = 1 + solve(arr,i+1,i);
        }
        int skip = solve(arr,i+1,p);
        
        if(p != -1){
            dp[i][p] = max(taken,skip);
        }
        
        return max(taken,skip);
    }
    int lis(vector<int>& arr) {
        
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,-1);
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends