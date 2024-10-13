//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int mid = (start+end)/2;
        
        while(start<=end)
        {
            if(arr[mid] == k)
            {
                return mid;
                break;
            }
            else if(k < arr[mid])  // go to left wala part
            {
                end = mid-1;
            }
            else if(k > arr[mid])  // go to right wala part
            {
                start = mid+1;
            }
            
            mid = (start+end)/2;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int res = ob.binarysearch(arr, k);
        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends