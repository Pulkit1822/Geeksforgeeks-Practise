//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
         vector<int> sequence;
        unordered_set<int> seen;

        sequence.push_back(0);
        seen.insert(0);

        for (int i = 1; i < n; ++i) {
            int prev = sequence[i - 1];

            int next = prev - i;
            if (next > 0 && seen.find(next) == seen.end()) {
                sequence.push_back(next);
                seen.insert(next);
            } else {
                next = prev + i;
                sequence.push_back(next);
                seen.insert(next);
            }
        }

        return sequence;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends