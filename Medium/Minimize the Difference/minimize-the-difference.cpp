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
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
public:
    int minimizeDifference(int arraySize, int windowSize, vector<int> &elements) {
        vector<int> leftMin(arraySize, 1e9);
        vector<int> leftMax(arraySize, 0);
        vector<int> rightMin(arraySize, 1e9);
        vector<int> rightMax(arraySize, 0);
        
        leftMin[0] = elements[0];
        leftMax[0] = elements[0];
        for (int i = 1; i < arraySize; i++) {
            leftMin[i] = min(elements[i], leftMin[i - 1]);
            leftMax[i] = max(elements[i], leftMax[i - 1]);
        }
        
        rightMin[arraySize - 1] = elements[arraySize - 1];
        rightMax[arraySize - 1] = elements[arraySize - 1];
        for (int i = arraySize - 2; i >= 0; i--) {
            rightMin[i] = min(elements[i], rightMin[i + 1]);
            rightMax[i] = max(elements[i], rightMax[i + 1]);
        }
        
        int answer = 1e9;
        int i = windowSize + 1;
        while (i < arraySize) {
            answer = min(max(leftMax[i - windowSize - 1], rightMax[i]) - min(leftMin[i - windowSize - 1], rightMin[i]), answer);
            i++;
        }
     
        answer = min(rightMax[windowSize] - rightMin[windowSize], answer);
        answer = min(leftMax[arraySize - windowSize - 1] - leftMin[arraySize - windowSize - 1], answer);
        return answer;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends