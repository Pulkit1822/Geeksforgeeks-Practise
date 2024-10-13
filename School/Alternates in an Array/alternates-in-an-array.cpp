//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // arr[] is the array
    void print(vector<int> &arr) {
        // code here
        for(int i=0;i<arr.size();i++)
        {
            if(i%2==0)
            {
                cout<<arr[i]<<" ";
            }
         
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
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
        ob.print(arr);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends