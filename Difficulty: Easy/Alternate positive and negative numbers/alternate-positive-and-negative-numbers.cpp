//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos, neg;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i] >= 0)
                pos.push_back (arr[i]);
            else
                neg.push_back(arr[i]);
        }
        
        
        
        vector<int> ans;
        
        int pptr=0, nptr=0;
        int turn=1;
        while(pptr<pos.size() && nptr<neg.size()){
            if(turn == 1){


                ans.push_back(pos[pptr]);
                pptr++;
                turn =-1;
            }
            else{

                ans.push_back(neg[nptr]);
                nptr++;
                turn=1;
            }
        }
        
        if(pptr <pos.size()){
            while(pptr < pos.size()){
                ans.push_back(pos[pptr]);
                pptr++;
            }
        }
        
        
        if(nptr < neg.size()){
            while(nptr < neg.size()){
                ans.push_back(neg[nptr]);
                nptr++;
            }
        }
        arr=ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends