class Node:
    def __init__(self, val=0):
        self.val = val
        self.next = None


def middleNode(head: Node) -> Node:
    counter=0
    items=[]
    for item in head:
        counter +=1
        items.append(item)

    middle = round(counter / 2)
    result = items[middle:]
   
    return result 

head = [1,2,3,4,5,6]
print(middleNode(head))



class Node:
    def __init__(self, val=0):
        self.val = val
        self.next = None


def middleNode(head: Node) -> Node:
    slow = fast = head

    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
    return slow