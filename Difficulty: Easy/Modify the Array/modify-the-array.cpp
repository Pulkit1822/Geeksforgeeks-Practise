//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // Function to modify and rearrange the array
    std::vector<int> modifyAndRearrangeArray(std::vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return {}; // Handle empty array case

        std::vector<int> result;
        for (int i = 0; i< n; ++i) {
            // If current element is non-zero and equal to the next one
            if (i < n - 1 && arr[i] == arr[i + 1] &&   arr[i] != 0) {
                
                
                
                result.push_back(arr[i] * 2); // Merge and double the value
                ++i; // Skip the next element as it is merged
            } else if (arr[i]!= 0) {
                result.push_back(arr[i]); // Add non-zero elements
            }
        }
        
        
        
        // Fill the rest of the result with zeros
        while (result.size() < n) {
            result.push_back(0);
        }
        
        return result;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends