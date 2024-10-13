//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        
        if(sum & 1) return 0;
        
        int targetSum = sum / 2;
        
        for(int i{}, c{}; i < a.size(); i++) {
            c += a[i];
            if(c == targetSum) return 1;
        }
        
        return 0;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends