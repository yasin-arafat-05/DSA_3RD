class Node:
    def __init__(self,data=None,next=None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None
    #_________________ Insert Element At Head _________________
    def insertAtHead(self,data):
        node = Node(data,self.head)
        self.head = node
        
    #_________________ Insert Element At Tail _________________
    def insertAtTail(self,data):
        # if head==None
        if self.head==None:
            node = Node(data,self.head)
            self.head = node
        ptr = self.head
        while ptr.next:
            ptr = ptr.next
        node = Node(data,ptr.next)
        self.head = node
    
    #__________________________ Print All The Element ___________________________
    def traverseAllElement(self):
        ptr = self.head
        ans = ""
        while ptr:
            if ptr.next: 
                suffix = "-->"
            else:
                suffix = ""   
            ans += (str) (ptr.data) + suffix
            ptr = ptr.next
        print(ans)

if __name__ == '__main__':
    ll = LinkedList()
    ll.insertAtHead(5)
    ll.insertAtHead(6)
    ll.insertAtHead(7)
    ll.insertAtHead(8)
    ll.insertAtHead(9)
    ll.traverseAllElement()