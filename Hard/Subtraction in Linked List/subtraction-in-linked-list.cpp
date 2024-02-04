//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends


//User function Template for C++

class Solution 
{
    public:
    Node * reverse(Node * head) 
    {
        Node * prev = nullptr, * cur = head;
        while(cur)
        {
            Node * next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    pair<Node *, Node *> subtract(Node * head1, Node * head2) 
    {
        LinkedList Answer, Sec;
        int C = 0;
        
        while(head1 || head2)
        {
            int cur = (head1 ? head1 -> data : 0) - (head2 ? head2 -> data : 0) - C;
            C = cur < 0;
            if(C != 1)
            {
                Answer.insert(cur);
                Sec.insert(0);
            }
            else
            {
                if((head1 && head1 -> next) || (head2 && head2 -> next))
                {
                    Answer.insert(10 + cur);
                    Sec.insert(0);
                }
                else
                {
                    Sec.insert(abs(cur));
                }
                
            }
            
            if(head1)
                head1 = head1 -> next;
            if(head2)
                head2 = head2 -> next;
        }
        if(C != 1)
        {
            return {Answer.head, nullptr};
        }
        else
        {
             return {Sec.head, Answer.head};
        }  
    }
    
    Node* subLinkedList(Node* head1, Node* head2) 
    {
        head1 = reverse(head1);
        head2 = reverse(head2);
        pair<Node *, Node *> result = subtract(head1, head2);
        Node * Output;
        if(result.second)
        {
            head1 = result.first;
            head2 = result.second;
            
            Output = subtract(head1, head2).first;
        }
        else
        {
            Output = result.first;
        }
        Output = reverse(Output);
        while(Output -> data == 0 && Output -> next)
            Output = Output -> next;
        return Output;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends