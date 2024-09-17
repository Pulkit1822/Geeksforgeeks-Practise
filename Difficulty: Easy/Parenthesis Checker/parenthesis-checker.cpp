//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
  public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        
        // Your code here
        int i=0;
        stack<char>s;
        int a=x.size();
        if (a==1 || a%2!=0){
            return false;
        //     exit(0);
            // break;
        }
        while(a--){
            char ch= x[i];
            
            if (ch=='(' || ch=='[' || ch=='{'){
               s.push(ch); 
            }
            if(s.empty()){
                return false;
            }
             if (ch==')'|| ch==']'|| ch=='}'){
                 if ((ch==')' && s.top()=='(') || (ch==']' && s.top()=='[') || (ch=='}' && s.top()=='{'))
                 {
                     s.pop();
                 }
                 else {
                     return false;
                     break;
                 }
             }
             
            //   i++; }
             i++;
        
        
    }
    if (!s.empty()){
        return false;
        
    }
    return true;
    }

};


//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends