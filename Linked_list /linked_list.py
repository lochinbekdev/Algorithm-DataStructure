class Node:
    def __init__(self,data):
        self.data=data
        self.next=None


class LinkedList:
    def __init__(self):
        self.head=None


    def append(self,data):
        new_node=Node(data)
    
        if self.head is None:
            self.head = new_node
            return
        
        current = self.head
        while current.next:
            current = current.next
        current.next=new_node

    def prepend(self,data):
        new_node=Node(data)
        new_node.next =self.head
        self.head=new_node

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current=current.next
        print("None")


    def delete(self,data):
        current = self.head
        print(f"This is a next: {current.next.data}")
        print(f"This is data : {current.data}")


        #first statement : rm first element 
        if current and current.data == data:
            self.head=current.next
            return

        while current:
            if current.next and current.next.data == data:
                current.next =current.next.next
                return
            current=current.next



ll=LinkedList()
ll.append(20)
ll.append(30)
ll.append(40)
ll.prepend(10)
ll.delete(88)
ll.print_list()
