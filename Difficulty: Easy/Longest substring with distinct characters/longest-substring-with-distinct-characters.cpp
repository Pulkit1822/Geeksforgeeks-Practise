//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n=s.size();
        int maxCnt=0;
        int r=0,l=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]==2){
                mp[s[l]]--;
                l++;
            }
            maxCnt=max(maxCnt,r-l+1);
            r++;
        }
        return maxCnt;
    }


};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends