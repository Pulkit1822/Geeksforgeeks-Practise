//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int diff = 3, len = INT_MAX;
        vector<int> count(3, 0);
        int first = 0, second=0;
        while(second < s.size())
        {
            while(diff && second < s.size())
            {
                if(count[s[second]-'0'] == 0)
                diff--;
                count[s[second]-'0']++;
                second++;
            }
            if(diff==0)
            {
                len = min(len, second - first);
                
                while(diff != 1)
                {
                    len = min(len, second - first);
                    count[s[first]-'0']--;
                    
                    if(count[s[first]-'0'] == 0)
                    diff++;
                    
                    first++;
                }
            }
        }
        return (len == INT_MAX) ? -1 : len;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends