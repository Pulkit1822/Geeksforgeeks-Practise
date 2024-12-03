//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

        void constructLps(string &pat, vector<int> &lps) {

        int len = 0;
        
        // lps[0] is always 0
        lps[0] = 0;
        
        int i = 1;
        while (i < pat.length()) {
            
            // If characters match, increment the size of lps
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            
            // If there is a mismatch
            else {
                if (len != 0) {
                    
                    len = lps[len - 1];
                }
                else
                {
                    // If no matching prefix found, set lps[i] to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {

        string sTest = s2 + s2;
        // n & m string lengths
        int n = sTest.size(), m = s1.size();
        // declare and construct the LPS vector
        vector<int> lps(n, 0);
        constructLps(s1, lps);
        // i & j indexes to iterate the strings
        int i=0, j=0;
        // iteration loop
        while(i<n)
        {
            
            if(sTest[i] == s1[j])
            {
                i++;
                j++;
                
                if(j==m)
                {
                    return true;
                }
            }
            
            else
            {
                
                if(j != 0)
                {
                    j = lps[j - 1];
                }
                
                else
                {
                    i++;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends