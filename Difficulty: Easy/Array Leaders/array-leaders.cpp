//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
       //optimal solution
        vector<int> ans;
         // Last element of an array is always a leader,
         // push into ans array. 
        int maxi = INT_MIN;
         // Start checking from the end whether a number is greater
         // than max no. from right, hence leader.
        for(int i = n-1; i>=0; i--) // back traversal
        { 
            if(arr[i]>=maxi)
            {
                ans.push_back(arr[i]);
            }
            //keep track of right maximum
            maxi = max(maxi,arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t; // testcases
    while (t--) {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends