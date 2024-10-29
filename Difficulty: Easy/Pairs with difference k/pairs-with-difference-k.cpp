//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:


    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int ans = 0;


        for (int num : arr) {
            freq[num]++;
        }

        for (const auto& pair : freq) {
            int num = pair.first;
            int count = pair.second;
            if (k == 0) {
                ans += count * (count - 1) / 2;
            } else {
                if (freq.count(num + k)) {
                    ans += count * freq[num + k];
                }
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
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends