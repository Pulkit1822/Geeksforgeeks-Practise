//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

       bool check(vector <int>& stalls, int k, int dist){
        int prev = stalls[0];
        int n = stalls.size();
        
        k--;
        for(int i = 1; i < n; i++){
            if(k == 0) break;
            int diff = stalls[i] - prev;
            if(diff >= dist){
                prev = stalls[i];
                k--;
            }
            else continue;
        }
        
        return (k == 0);
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int ans = 1;
        int l = 0;
        int r = stalls[n-1] - stalls[0];
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(stalls, k, mid)){
                l = mid + 1;
                ans = mid;
            }
            else{
                r = mid-1;
            }   
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends