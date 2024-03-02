//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
	static bool cmp(string a,string b){
        string first=a+b;
        string second=b+a;
        return first>second;
    }
    
	string printLargest(int n, vector<string> &arr){
	    sort(arr.begin(),arr.end(),cmp);
        string ans="";
        for(int i=0;i<arr.size();i++) 
            ans+=arr[i];
        return ans;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends