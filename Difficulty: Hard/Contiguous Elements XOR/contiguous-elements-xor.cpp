//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32


// } Driver Code Ends
//User function template for C++

// arr : given array
// n : size of the given array

//User function template for C++
struct TrieNode{
       bool isLeaf;
       TrieNode* children[2];
       int value;
       TrieNode(){
           isLeaf = false;
           children[0] = NULL;
           children[1] = NULL;
           value = 0;
       }
   };
  
   
   void insert(TrieNode* root, int n, int val){
       TrieNode* curr = root;
       for(int i = n - 1; i >= 0; i--){
           int curr_bit = (val & (1 << i)) ? 1 : 0;
           if(curr->children[curr_bit] == NULL){
               curr->children[curr_bit] = new TrieNode();  
           }
           curr = curr->children[curr_bit];
       }
       curr->value = val;
       curr->isLeaf = true;
       return;
   }
   
   
  int search(TrieNode* root, int n, int val){
       TrieNode* curr = root;

       for(int i = n - 1; i >= 0; i--){
           int curr_bit = val & (1 << i) ? 1 : 0;
           if(curr->children[1 - curr_bit] != NULL){
               curr = curr->children[1 - curr_bit];
           }
           else if(curr->children[curr_bit] != NULL){
               curr = curr->children[curr_bit];
           }
       }
       return (curr->value ^ val);
   }    

class Solution
{
   public:
   
   int maxSubarrayXOR(int arr[], int n)
   {

       TrieNode* root = new TrieNode();
       
       vector<int> prefix_xor(n, 0);
       prefix_xor[0] = arr[0];
       int max_element = arr[0];
       for(int i = 1; i < n; i++){
           prefix_xor[i] = prefix_xor[i - 1]^arr[i];
           max_element = max(max_element, prefix_xor[i]);
       }
       
       int numberOfDigit = log2(max_element) + 1;
       
       for(int i = 0; i < n; i++){
           int x = prefix_xor[i];
           insert(root, numberOfDigit, x);
       }
       int ans = prefix_xor[0];
       
       for(int i = 0; i < n; i++){
           ans = max(ans, search(root, numberOfDigit, prefix_xor[i]));
       }
       return ans;
   }
};




//{ Driver Code Starts.

int main(){
  
  int t;
  cin >> t;
  
  while(t--){
    
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0;i<n;i++){
      cin >> arr[i];
    }
    Solution obj;
    cout << obj.maxSubarrayXOR(arr, n) << endl;
    
  
cout << "~" << "\n";
}
  
  return 0;
}
// } Driver Code Ends