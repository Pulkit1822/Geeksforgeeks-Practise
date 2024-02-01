//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        set<char> s;
        for(int i=0; i<str.length(); i++){
            if(str[i] >='A' && str[i] <= 'Z') str[i] = char(tolower(str[i]));
            
            if(str[i] >= 'a' && str[i] <= 'z')
            s.insert(str[i]);
        }
        
        if(s.size() == 26) return true;
        
        return false;
        
    }

};


//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends