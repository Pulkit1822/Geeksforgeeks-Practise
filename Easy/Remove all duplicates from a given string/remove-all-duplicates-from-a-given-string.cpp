//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    unordered_map<char,int> m;
	    string ans="";
	    for(char c:str){
	        m[c]++;
	        if(m[c]==1){
	            ans=ans+c;
	        }
	    }
	    return ans;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends