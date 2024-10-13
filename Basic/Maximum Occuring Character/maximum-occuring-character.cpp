//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};          //initialize an array for 26 characters and storing the count of each character 0 at initially
    
    
        for(int i=0; i<str.length(); i++)
        {
            char ch = str[i];
            int number = 0;
    
            //if character is lowercase
            if(ch>='a' && ch<='z')
            {
                number = ch - 'a';      // to find index where character is stored in array
            }
            else if (ch>='A' && ch<='Z')  //uppercase      basically we want it to count only 1 time whether char is in U.C or L.C
            {
                number = ch - 'A';
            }
    
            arr[number]++;
        }
    
        //find maximum
        int max = -1, ans = 0;
        for(int i=0; i<26; i++)      //running loop for 26 alphabets 
        {
            if(arr[i]>max)
            {
                ans = i;         //record index of char which has highest occurrence
                max = arr[i];       //record char which has highest occurrence
            }  
        }
        char finalAns = 'a' + ans;       // adding base ascii(a's ascii value) to the index of char whose occurrence is max(ans) => we'll get actual ascii value of that char
        return finalAns;      // finally returning that char whose occurrence is max
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends