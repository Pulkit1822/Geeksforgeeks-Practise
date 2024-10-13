//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> arranged(vector<int>& arr) {
        // code here           //optimal approach
        int n = arr.size();
        vector<int> ans(n,0);
        int posIndex  = 0, negIndex = 1;   //phla element +ve 0th index pe, fir phla -ve 1st index pe

        for (int i = 0; i<n; i++)
        {
            if(arr[i] > 0)
            {
                ans[posIndex] = arr[i];
                posIndex += 2;     //phla +ve place hone ke bad next +ve uski position se 2 age wali position pr ayega
            }
            else{
                ans[negIndex] = arr[i];
                negIndex += 2;         //phla -ve place hone ke bad next +ve uski position se 2 age wali position pr ayega
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
        Solution obj;
        vector<int> ans = obj.arranged(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends