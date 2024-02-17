//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    int StringToInt(string x){
        int num = x[x.size()-1]- '0';
        if(x.size() > 1){
            num = (x[x.size()-2] - '0')*10+num;
        }
        return num;
    }
  public:
    int getLastDigit(string a, string b) {
        if(a.size() == 1 && a[0] == '0' && b.size() == 1 && b[0] == '0'){
            return 1;
        }
        if(a.size() == 1 && a[0] == '0'){
            return 0;
        }
        if(b.size() == 1 && b[0] == '0'){
            return 1;
        }
        int base = a[a.size() - 1] - '0';
        int power = StringToInt(b);
        int res = power % 4 == 0 ? 4 : power % 4;
        int answer = pow(base,res);
        int result = answer%10;
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.getLastDigit(a,b) << endl;
    }
    return 0;
}
// } Driver Code Ends