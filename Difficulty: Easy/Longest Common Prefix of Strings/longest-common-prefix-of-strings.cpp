//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n=INT_MAX;
        for(string x:arr) {int m=x.size();n = min(n,m);}
        string ans="";
        for(int i=0;i<n;i++){
            char ch=arr[0][i];
            int count=0;
            for(auto &x:arr) if(ch==x[i]) count++;
            if(count==arr.size()) ans+=ch;
            else return ans==""?"-1":ans;
        }
        return ans==""?"-1":ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends