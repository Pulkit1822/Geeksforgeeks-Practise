//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int leftProd = 1, rightProd = 1;
        int maxProduct = INT_MIN;

        // Traverse from left to right
        for (int i = 0; i < n; i++) {
            leftProd *= arr[i];
            maxProduct = max(maxProduct, leftProd);
            if (leftProd == 0) leftProd = 1; // Reset if zero is encountered
        }

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            rightProd *= arr[i];
            maxProduct = max(maxProduct, rightProd);
            if (rightProd == 0) rightProd = 1; // Reset if zero is encountered
        }

        return maxProduct;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends