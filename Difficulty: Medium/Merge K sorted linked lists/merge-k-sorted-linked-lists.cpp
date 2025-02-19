//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends

/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
   Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node* dummy=new Node(-1);
        Node* nxt=dummy;
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, 
        greater<pair<int, Node*>>>pq;
        
        for(auto *it:arr){
            pq.push({it->data, it});
        }
        
        while(!pq.empty()){
            auto it=pq.top();
            int val=it.first;
            Node* node=it.second;
            pq.pop();
            
            nxt->next=node;
            nxt=node;
            if(node->next){
                pq.push({node->next->data, node->next});
            }
        }
        
        return dummy->next;
    }
};





//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends