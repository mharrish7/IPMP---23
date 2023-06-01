#User function Template for python3

'''
#LinkedList Node
class LNode:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None
        
#Tree Node        
class TNode:
    def __init__(self, data):
        self.data=data
        self.left = self.right = None
'''

class Solution:
    def sortedListToBST(self, head):
        def findmid(head,end):
            slow = head
            fast = head 
            
            while fast != end and fast.next != end:
                fast = fast.next.next
                slow = slow.next 
            
            return slow 
            
        def rec(head,end):
            m = findmid(head,end)
            
            if head == end:
                return 
            new = TNode(m.data)
            new.left = rec(head,m)
            new.right = rec(m.next,end)
            
            return new 
        
        return rec(head,None)
            
            
            
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

#Initial Template for Python 3
# Node Class
class LNode:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None
        
class TNode:
    def __init__(self, data):
        self.data=data
        self.left = self.right = None

# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_value):
        new_node = LNode(new_value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node    
            return
        self.tail.next = new_node
        self.tail = new_node
        
# prints the elements of linked list
def preOrder(root):
    if root == None:
        return
    
    print(root.data, end=" ")
    preOrder(root.left)
    preOrder(root.right)

if __name__ == '__main__':
    for _ in range(int(input())):
       
        n=int(input())
        
        a = LinkedList() # create a new linked list 'a'.
        #b = LinkedList() # create a new linked list 'b'.
        
        nodes_a = list(map(int, input().strip().split()))
        #nodes_b = list(map(int, input().strip().split()))
        
        for x in nodes_a:
            a.append(x)
        
        ob= Solution()
        root= ob.sortedListToBST(a.head)
        preOrder(root)
        
        print()

# } Driver Code Ends