//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int myAtoi(char *s) {
        string str(s);
        int sign = 1;
        int index=0;
        int n = str.size();
        while(index<n && (str[index]==' '))
            index++;
        long long finalResult = 0;
        for(int i=index;i<n;i++) {
            if(i==0 && str[i]=='-')
                sign=-1;
            else if(str[i]>='0' && str[i]<='9')
                finalResult=finalResult*10 + (str[i]-'0');
            else
                break;
            if(sign==-1 && -finalResult<INT_MIN)
                return INT_MIN;
            if(sign==1 && finalResult>INT_MAX)
                return INT_MAX;
        }
        return sign*finalResult;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends