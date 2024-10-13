//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
        // code here.
    long long result = 0;
    long long place = 1;

    // Convert n to base-9 representation
    while (n > 0) {
        int remainder = n % 9;    // Get the last digit in base-9
        result += remainder * place; // Form the number in base-10
        n /= 9;    // Move to the next digit
        place *= 10;  // Shift to the next decimal place
    }

    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends