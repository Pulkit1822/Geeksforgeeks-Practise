//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  private:
    vector<int> arr;
    int k;
    int getMin(int m) {
        // arr[0] +k,... arr[m-1]+k, arr[m]-k,...arr.back() - k
        if (m >= arr.size()) {
            return arr.back() - arr[0];
        }
        if (m <= 0) {
            return arr.back() - arr[0];
        }
        int new_min = min(arr[0] + k, arr[m] - k);
        int new_max = max(arr[m - 1] + k, arr.back() - k);
        //printf("a[%d]: %d new_nax: %d new_min: %d\n", m, arr[m], new_max, new_min);
        return new_max - new_min;
    }
  public:
    int getMinDiff(vector<int> &_arr, int k) {
        this->arr = _arr;
        sort(arr.begin(), arr.end());
        this->k = k;

        int r = arr.back() - arr[0];
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < k) {
                continue;
            }
            //printf("i: %d\n", i);
            if (getMin(i) < r) {
                r = getMin(i);
                //printf("a[%d]: %d r: %d \n", i, arr[i], r);
            }
        }
        return r;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends