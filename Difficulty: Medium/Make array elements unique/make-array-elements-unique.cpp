//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minIncrements(std::vector<int> arr) {
        std::sort(arr.begin(), arr.end());
        int value = arr[0];
        int count = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i - 1] >= arr[i]) {
                count += value - arr[i] + 1;
                value += 1;
                arr[i] = value;
            } else {
                value = arr[i];
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends