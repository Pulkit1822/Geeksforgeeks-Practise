//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string binaryNextNumber(string s) {
        int cnt = 0;
        for(auto it : s){
            if(it == '0'){
                cnt++;
            }
            else{
                break;
            }
        }
        int carry = 0;
        int j = s.size() - 1;
        int i = 0;
        string t = "1";
        string result = "";
        while(i >= 0 || j >= cnt || carry > 0){
            int sum = carry;
            if(i >= 0){
                sum += t[i] - '0';
                i--;
            }
            if(j >= 0){
                sum += s[j] - '0';
                j--;
            }
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends