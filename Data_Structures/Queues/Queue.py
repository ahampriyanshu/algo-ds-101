class FifoList:
    def __init__(self):
        self.data = {}
        self.nextin = 0
        self.nextout = 0
    def append(self, data):
        self.nextin += 1
        self.data[self.nextin] = data
    def pop(self):
        self.nextout += 1
        result = self.data[self.nextout]
        del self.data[self.nextout]
        return result
    def display(self):
        print(self.data.values())


if __name__=='__main__':
    f= FifoList()
    loop= True
    while(loop==True):
        o=int(input('1. Insert, 2. Delete, 3. Display, 4. End '))
        if(o==1):
            a=int(input('Enter element: '))
            f.append(a)
        elif(o==2):
            f.pop()
            print('Element Deleted!')
        elif(o==3):
            f.display()
        elif(o==4):
            loop=False
        else:
            print('Invalid operation!')