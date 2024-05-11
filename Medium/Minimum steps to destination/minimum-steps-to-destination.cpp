//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        // code here
           int currSum = 0;
        int ans = 0;
        for(int i=1;true;i++){
            if(currSum < d){
                currSum+=i;
            }
            else{
                if((currSum - d)%2 == 0){
                    return ans;
                }
                else{
                    currSum+=i;
                }
            }
            ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends