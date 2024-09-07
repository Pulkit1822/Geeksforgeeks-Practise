//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n=arr.size(),i;
        long step=arr[0],jump=1,mx=arr[0];
        if(n==1)
        {
            return 1;
        }
        if(arr[0]==0)
        {
            return -1;
        }
        for(i=1;i<n;i++)
        {
            if(i==(n-1))
            {
                return jump;
            }
            mx=max(mx,1L*arr[i]+i);
            step--;
            if(!step)
            {
                jump++;
                if(i>=(mx))
                {
                    return -1;
                }
                step=mx-i;
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends