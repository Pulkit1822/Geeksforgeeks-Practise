//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string compareFrac(string str) {
        int n=str.size();
        int a=0,b=0,c=0,d=0;
        int i=0;
        for(i;i<n;i++){
            if(str[i]=='/') break;
            a= a*10 + (str[i]-'0');
        }
        i++;
        for(i;i<n;i++){
            if(str[i]==',') break;
            b= b*10 + (str[i]-'0');
        }
        i+=2;
        for(i;i<n;i++){
            if(str[i]=='/') break;
            c= c*10 + (str[i]-'0');
        }
        i++;
        for(i;i<n;i++){
            d= d*10 + (str[i]-'0');
        }
        if(a==c && a==0) return "equal";
        double t1=double(a)/b;
        double t2=double(c)/d;
        if(t1>t2){
            string s1=to_string(a) + '/' + to_string(b);
            return s1;
        }
        else if(t1<t2){
            string s1=to_string(c) + '/' + to_string(d);
            return s1;
        }
        else{
            return "equal";
        }
        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends