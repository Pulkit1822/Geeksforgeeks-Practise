//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    vector<string> ans;
   unordered_set<string> set;
   
   int isValid(string s) {
       stack<int> st;
       
       for(int i = 0; i < s.size(); i++) {
           if(s[i] == '(') {
               st.push('(');
           }else if(s[i] == ')') {
               if(st.size() == 0) {
                   st.push(')');
               }else if(st.top() == ')') {
                   st.push(')');
               }else if(st.top() == '(') {
                   st.pop();
               }
           }
       }
       return st.size();
   }
   
   void solve(string s, int invalid) {
       if(invalid < 0) return;
       if(invalid == 0) {
           int cnt = isValid(s);
           if(cnt == 0) {
               ans.push_back(s);
           }
           return;
       }
       
       for(int i = 0; i < s.size(); i++) {
           if(s[i] != ')' and s[i] != '(') {
               continue;
           }
           
           string l = s.substr(0, i);
           string r = s.substr(i+1);
           string a = l+r;
           
           if(set.find(a) == set.end()) {
               set.insert(a);
               solve(a, invalid - 1);
           }
       }
   }
   
   vector<string> removeInvalidParentheses(string s) {
       int invalidParen = isValid(s);
       solve(s, invalidParen);
       sort(ans.begin(), ans.end());
       return ans;
   }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends