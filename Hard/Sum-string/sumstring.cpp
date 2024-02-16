//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int isSumString(string s){
        int len = (int) s.size();
        for (int i = 1; i < len; i++) {
            for (int j = 1; i + j < len; j++) {
                if (checkSumStrUtil(s, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool checkSumStrUtil(string str, int beg, int len1, int len2) {
        string a = str.substr(beg, len1);
        string b = str.substr(beg + len1, len2);
        string c = stringSum(a, b);
        int len3 = (int)c.size();
        if (len3 > str.size() - len1 - len2 - beg) {
            return false;
        }
        if (c == str.substr(beg + len1 + len2, len3)) {
            
            if (beg + len1 + len2 + len3 == (int)str.size()) {
                return true;
            } else {
                return checkSumStrUtil(str, beg + len1, len2, len3);
            }
        }
        return false;
    }
    string stringSum(string str1, string str2)
    {
        if (str1.length() > str2.length())
            swap(str1, str2);
        string str = "";
        int n1 = str1.length(), n2 = str2.length();
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
     
        int carry = 0;
        for (int i=0; i<n1; i++)
        {
            int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
        for (int i=n1; i<n2; i++)
        {
            int sum = ((str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
        if (carry)
            str.push_back(carry+'0');
        reverse(str.begin(), str.end());
     
        return str;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends