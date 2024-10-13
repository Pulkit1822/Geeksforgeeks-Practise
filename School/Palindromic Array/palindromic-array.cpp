//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
  public:
    bool PalinArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        int count = 0;
    
    	for(int i=0; i<n; i++)
    	{
    	    int d,rev=0;
    	    int x = arr[i];
    	   
    	    
    	    while(arr[i]>0)
    	    {
    	        d = arr[i]%10;
    	        rev = rev*10 + d;
    	        arr[i] = arr[i]/10;
    	    }
    	    
    	    if(x == rev)
    	    {
    	        count++;
    	    }
    	    else
    	    {
    	        count--;
    	    }
    	    
    	}
    	if(count == n)
    	{
    	    return 1;
    	}
    	else
    	{
    	    return 0;
    	}
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << (ob.PalinArray(arr) ? "true" : "false") << endl;
    }

    return 0;
}

// } Driver Code Ends