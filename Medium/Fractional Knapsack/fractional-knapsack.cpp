//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
 public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<int,int>>A(n);
        for(int i=0;i<n;i++)
            A[i]={arr[i].value,arr[i].weight};
        sort(A.begin(),A.end(),[&](pair<int,int>&A,pair<int,int>&B)
        {
            return A.first*B.second > B.first*A.second; 
        });
        double ans=0;
        for(auto i:A)
        {
            if(i.second<=W)
                ans+=i.first,W-=i.second;
            else 
                ans+=(i.first*1.0/i.second)*W,W=0;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends