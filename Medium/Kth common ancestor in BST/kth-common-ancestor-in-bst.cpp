//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends

//User function Template for C++

/*// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};*/


class Solution
{
    public:
    vector<int> arr;
    bool visited = false;
    Node* LCA(Node* root, int x, int y) {
        if(!root)return NULL;
        if(root->data==x or root->data==y)return root;
        auto a=LCA(root->left,x,y),b=LCA(root->right,x,y);
        if(a and b)return root;
        if(a)return a;
        return b;
    }
    
    void rootToNode(Node* root, Node* node) {
        if(!root)return;
        if(!visited)arr.push_back(root->data);
        if(root==node)visited=true;
        rootToNode(root->left, node);
        rootToNode(root->right, node);
        if(!visited)arr.pop_back();
    }
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        auto node = LCA(root,x,y);
        rootToNode(root,node);
        if(arr.size()<k)return -1;
        return arr[arr.size()-k];
    }
};




//{ Driver Code Starts.

int main ()
{

	int t;
	cin >> t;
	cin.ignore();

	while (t--)
	{
	
		string inp;
		getline(cin, inp);
		
		int k,x,y;
		cin>>k>>x>>y;
		cin.ignore();

		struct Node* root = buildTree(inp);

        Solution ob;
		int ans = ob.kthCommonAncestor(root,k,x,y);
		cout<<ans<<endl;

	}

	return 0;
}
// } Driver Code Ends