//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
 public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string> st;
        for(int i = 0; i < S.length(); i++) {
            string word = "";
            while(S[i] != '.' && i < S.length()) {
                word += S[i];
                i++;
            }
            st.push(word);
        }
        string ans = "";
        while(!st.empty()) {
            ans = ans + st.top() + '.';
            st.pop();
        }
        ans.pop_back();
        return ans;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends