//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
          sort(arr.begin(),arr.end());
        int ans = INT_MAX;
        int n = arr.size();
        for(int i=0;i<n-2;i++){
            int s=i+1,e=n-1;
            while(s<e){
                int sum=arr[i]+arr[s]+arr[e];
                if(abs(target-sum)<(abs(target-ans))) ans = sum;
                else if(abs(target-sum)==abs(target-ans)) ans = max(ans,sum);
                if(sum>target)e--;
                else s++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends