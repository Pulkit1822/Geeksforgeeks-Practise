//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countNumberswith4(int n)
    {
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            int x=i;
            while(x)
            {
                if(x%10==4) {ans++;break;}
                x=x/10;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends