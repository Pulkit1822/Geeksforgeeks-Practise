//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string removeKdigits(string num, int k) {
        int siz = num.length();
        deque<int>s;
        s.push_back(num[0]-'0');
        for(int i=1; i<siz; i++){
                int d = num[i]-'0';
                    while(k>0 && !s.empty() && s.back()>d){
                        s.pop_back();
                        k--;
                    }if(d!=0 || !s.empty() ){
                        s.push_back(d);
                    }

        }
        
        while(k>0 && !s.empty()){
            s.pop_back();
            k--;
        }

        string result="";
        if(s.empty()){
            return "0";
        }
        while (!s.empty()) {
        result+= s.front() + '0'; 
        s.pop_front();
        }
        return result; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends