class node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

var findList = function(first, second) {
    if(!first && !second) {
        return true;
    }
    if(!first || !second) {
        return false;
    }

    ptr1 = first;
    ptr2 = second;

    while(ptr2) {
        ptr2 = second;

        while(ptr1) {
            if(!ptr2) {
                return false;
            } else if(ptr1.value === ptr2.value) {
                ptr1 = ptr1.next;
                ptr2 = ptr2.next;
            } else {
                break;
            }
        }
        if(!ptr1) {
            return true;
        }
        ptr1 = first;
        second = second.next;
    }
    return false;
}

node_a = new node(1);
node_a.next = new node(2);
node_a.next.next = new node(3); 
node_a.next.next.next = new node(4); 
node_b = new node(1); 
node_b.next = new node(2); 
node_b.next.next = new node(1); 
node_b.next.next.next = new node(2); 
node_b.next.next.next.next = new node(3); 
node_b.next.next.next.next.next = new node(4);  

if(findList(node_a, node_b)) {
    console.log("List Found");
} else {
    console.log("List Not Found");
}

