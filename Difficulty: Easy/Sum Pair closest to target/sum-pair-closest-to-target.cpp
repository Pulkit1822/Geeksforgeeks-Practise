//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& v, int k) {
        // code here
        sort(v.begin(),v.end());
        int i = 0;
        int j = v.size() - 1;
        int diff = INT_MAX;
        vector<int> ans; 
        while(i < j){
            int x = v[i]+v[j];
            
            if(diff > abs(k-x)){
                diff = abs(k-x);
                ans.clear();
                ans.push_back(v[i]);
                ans.push_back(v[j]);
            }else if(diff == abs(k-x)){
                int sd = ans[1]-ans[0];
                if(sd < abs(k-x)){
                    ans.clear();
                    ans.push_back(v[i]);
                    ans.push_back(v[j]);
                }
            }
            
            if(x > k){
                --j;
            }else{
                ++i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends