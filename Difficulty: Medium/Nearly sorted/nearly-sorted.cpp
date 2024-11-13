//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        int n=arr.size();
          priority_queue < int, vector<int>, greater<int> > pq;
            for(int i=0;i<=k;i++){
                pq.push(arr[i]);
            }
            int j=k+1;
            int i=0;
            while(i<n &&j<n){
                arr[i]=pq.top();
                pq.pop();
                pq.push(arr[j]);
                j++;
                i++;
            }
            while(!pq.empty()){
                arr[i]=pq.top();
                pq.pop();
                i++;
            }
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
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends