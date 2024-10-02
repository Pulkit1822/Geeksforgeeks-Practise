//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   
    int rotateDelete(vector<int> &arr) {
        deque<int> dq(arr.begin(),arr.end());
        int k =1;
        while(dq.size() > 1){
            dq.push_front(dq.back());
            dq.pop_back();
            int idx=dq.size()-k;
            if(idx < 0){
                idx = 0;
                
            }
            dq.erase(dq.begin()+idx);
            k++;
        }
        return dq.front();
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends