//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        if(str.size()<26)
        {
            return false;
        }
        vector<int>v(26,0);
        int s=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]!=' '){
            v[str[i]-'a']++;
                s++;
            }
        }
        if(s<26)
        {
            return false;
        }
        
        int c=0;
        for(int i=0;i<26;i++)
        {
            if(v[i]==0)
            {
                c++;
            }
        }
        if(c>k)
        {
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends