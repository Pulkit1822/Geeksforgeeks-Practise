//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string transform(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<transform(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends



string transform(string s)
{
    // code here
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if(s[i - 1] == ' ') {
            s[i] = toupper(s[i]);
        }
    }
    return s;
    
}