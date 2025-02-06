//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
  Node*fun(int s,int e,int &indexPre,vector<int> &ino, vector<int> &pre,map<int,int>&mp)
  {
      if(s>e){
         return NULL; 
      }

       int rootVal = pre[indexPre++];
        Node* root = new Node(rootVal); // Create new node
        int x = mp[rootVal];   
        
      root->left=fun(s,x-1,indexPre,ino,pre,mp);
      root->right=fun(x+1,e,indexPre,ino,pre,mp);

      return root;
  }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &ino, vector<int> &pre) {
     int n=ino.size();
     if(n==0)return NULL;


     map<int,int>mp;
     for(int i=0;i<n;i++){
         mp[ino[i]]=i;
         }
         int indexPre=0;
    
     return  fun(0,n-1,indexPre,ino,pre,mp);
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends