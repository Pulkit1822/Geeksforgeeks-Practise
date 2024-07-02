//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        unordered_map<int,int> mp;
        
        while(head!=NULL){
            mp[head->data]++;
            head=head->next;
        }
        vector<int> list;
       
        for(auto it :mp){
            if(it.second==1)
                list.push_back(it.first);
        }
        sort(list.begin(),list.end());
        
        if(list.empty())
            return NULL;
        
        Node *pHead = new Node(list[0]);
        Node *p1 = pHead;
        for(int i=1;i<list.size();i++){
            p1->next=new Node(list[i]);
            p1=p1->next;
                   
            
        }
        
        return pHead;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends