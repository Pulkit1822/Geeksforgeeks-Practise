//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
   int findEquilibrium(vector<int> &arr) {
        // code here
        
        int left_sum = 0;
        int right_sum = 0;
        int arr_sum = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            arr_sum = arr_sum + arr[i];
        }
        
        for(int i = 0 ; i < arr.size() ; i++){
            right_sum = arr_sum - left_sum - arr[i];
            if(left_sum == right_sum){
                return i;
            }
            left_sum = left_sum + arr[i];
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends