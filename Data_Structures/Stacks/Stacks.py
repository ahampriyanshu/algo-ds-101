#Stacks using python list
class Stack:
    def __init__(self):
        self._data=[1,2,3]   

    def push(self,e):
        self._data.append(e)

    def pop(self):
        #remove and return the top element from the stack S
        if self.is_empty():
            raise Empty('Stack is empty')
        self._data.pop()

    def top(self):
        if self.is_empty():
            raise Empty('Stack is empty')
        return self._data[-1]

    def is_empty(self):
        return  len(self._data)==0

    def len(self):
        S=self._data
        return len(S)

    def get_stack(self):
        return self._data

S=Stack()

S.push(1)
S.push(2)
S.push(3)
S.push(56)
S.push(1)
S.push(2)
S.pop()
S.push(4)
S.pop()

print(S.get_stack())
print(S.top())
print(S.is_empty())
print(S.len())