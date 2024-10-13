//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longest(vector<string> &names) {
        // code here
        string longestName = "";
        int maxLength = 0;

        for (const string &name : names) {
            int currentLength = name.length();
            if (currentLength > maxLength) {
                maxLength = currentLength;
                longestName = name;
            }
        }

        return longestName;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> names;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        string str;
        while (ss1 >> str) {
            names.push_back(str);
        }
        Solution obj;
        string res = obj.longest(names);
        cout << res << "\n";
    }
}

// } Driver Code Ends