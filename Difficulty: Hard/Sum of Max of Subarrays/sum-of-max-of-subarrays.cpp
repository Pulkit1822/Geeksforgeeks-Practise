//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int sumOfMax(vector<int> &arr) {
       int ans=0;
       for(int i=0;i<arr.size();i++){
           int maxi=0;
           for(int j=i;j<arr.size();j++){
               maxi=max(maxi,arr[j]);
               ans=ans+maxi;
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.sumOfMax(arr);
        cout << result;
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends