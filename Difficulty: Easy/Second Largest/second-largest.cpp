//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
  public:
    // Function returns the second largest element
    int print2largest(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) {
            return -1; // Not enough elements to find the second largest
        }

        int first = INT_MIN, second = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] > first) {
                second = first;
                first = arr[i];
            } else if (arr[i] > second && arr[i] != first) {
                second = arr[i];
            }
        }

        return (second == INT_MIN) ? -1 : second;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends