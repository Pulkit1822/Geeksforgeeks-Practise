//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int largest(vector<int> &arr) {
        int maximum = arr[0];
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maximum )
            {
                maximum = arr[i];
            }
            
        }
        return maximum;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.largest(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends