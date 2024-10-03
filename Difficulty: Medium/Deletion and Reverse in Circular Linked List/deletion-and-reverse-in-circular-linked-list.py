
#User function Template for python3
'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''

class Solution:
    def reverse(self, head):
        if head is None or head.next == head:
            return head
        
        prev = None
        current = head
        next_node = None
        first_node = head

        while True:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
            
            if current == head:
                break
        
        head.next = prev
        head = prev
        return head
    
    def deleteNode(self, head, key):
        if head is None:
            return None
        
        current = head
        prev = None
        
        if head.data == key:
            if head.next == head:
                return None
            temp = head
            while temp.next != head:
                temp = temp.next
            temp.next = head.next
            head = head.next
            return head
        
        while current.next != head:
            if current.data == key:
                prev.next = current.next
                return head
            prev = current
            current = current.next
        
        if current.data == key:
            prev.next = head
        
        return head
        


#{ 
 # Driver Code Starts
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def printList(head):
    if head is None:
        print("empty")
        return

    temp = head
    while True:
        print(temp.data, end=" ")
        temp = temp.next
        if temp == head:
            break
    print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        key = int(input())

        head = Node(arr[0])
        tail = head
        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next
        tail.next = head  # Make the list circular

        ob = Solution()
        head = ob.deleteNode(head, key)
        head = ob.reverse(head)
        printList(head)

# } Driver Code Ends