//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int alternatingMaxLength(std::vector<int>& arr) {
        if (arr.empty()) return 0;
        
        int increase = 1; // Length of alternating sequence ending with an increase
        int decrease = 1; // Length of alternating sequence ending with a decrease
        
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i-1]) {
                increase = decrease + 1;
            } else if (arr[i] < arr[i-1]) {
                decrease = increase + 1;
            }
        }
        
        return std::max(increase, decrease);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends