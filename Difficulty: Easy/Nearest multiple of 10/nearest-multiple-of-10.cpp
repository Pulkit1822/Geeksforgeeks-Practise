//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   string roundToNearest(string str) {
        int n=str.length()-1;
        int num=str[n]-'0';
        
        
        bool flag=false;
        if(num>5){
            int i=n-1;
            for (i = n - 1; i >= 0; i--) {
                if (str[i] == '9') {
                    str[i] = '0';  
                } 
                
                
                else {
                    str[i]++;  
                    break;
                }
            }
            if (i<0 && str[0] == '0') {
                flag=true;
                str = "1" + str;
            }
        }
        
        
        if(flag==true){
            str[n+1]='0';
        }
        else{
            str[n]='0';
        }
        return str;

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends