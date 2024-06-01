//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string oddEven(string s) {
        // code here
        int x=0, y=0;
        vector<int>count(27,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a'+1]++;
        }
        
        for(int i=1;i<=26;i++){
            if(count[i]!=0 && count[i]%2==0 && i%2==0){
                x++;
            }
            else if(count[i]%2==1 && i%2==1){
                y++;
            }
        }
        int sum = x+y;
        if(sum%2==1) return "ODD";
        else return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends