//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here
        if(D*9<S) return "-1";
        string s="";
        for(int i=0;i<D;i++) s+="0";
        S--;
        s[0]='1';
        for(int i=D-1;i>0;i--) {
            if(S>9) {s[i]='9';S-=9;}
            else {s[i]=S+48;S=0;}
        }
        if(S!=0) s[0]=48+S+1;
        return s;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends