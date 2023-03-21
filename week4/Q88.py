# your task is to complete this function
# function should return a list of the
# two new heads
def mergeList(head1, head2):
    
    cur1 = head1
    cur2 = head2
    while(head1 != None and head2 != None):
        next1 = head1.next 
        next2 = head2.next 
        
        head1.next = head2
        head2.next = next1
        
        head1 = next1
        head2 = next2
    
    
    return [cur1, head2]


#{ 
 # Driver Code Starts
# Node Class    
class node:
    def __init__(self, val):
        self.data = val
        self.next = None
        
# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None

    def insert(self, val):
        new_node = node(val)
        new_node.data = val
        new_node.next = self.head
        self.head = new_node
        
def printList(head):
    while head:
        print(head.data, end=' ')
        head=head.next
    print()

def createList(arr, n):
    lis = Linked_List()
    for i in range(n):
        lis.insert(arr[i])
    return lis.head

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        head1 = createList(arr, n)
        n = int(input())
        arr = list(map(int, input().strip().split()))
        head2 = createList(arr, n)
        head = mergeList(head1, head2)
        printList(head[0])
        printList(head[1])
# Contributed by: Harshit Sidhwa

# } Driver Code Ends