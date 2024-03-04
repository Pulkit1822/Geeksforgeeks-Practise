//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        auto isPossible = [&](int targetSweetness) {
            int count = 0;
            int currSweetness = 0;
            for (int sweet : sweetness) {
                currSweetness += sweet;
                if (currSweetness >= targetSweetness) {
                    count++;
                    currSweetness = 0;
                }
            }
            return count >= K + 1;
        };

        int left = 1;  //min sweetness level
        int right = 0; //max sweetness level
        for (int sweet : sweetness) {
            right += sweet;
        }
        int maxSweetness = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(mid)) {
                maxSweetness = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return maxSweetness;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends