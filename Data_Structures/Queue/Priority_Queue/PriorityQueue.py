import queue

def using_list(l):
    newl=sorted(l)              #here we are setting priority on values as lower the value higher the priority
    for i in range(len(newl)):
        print(f"Current value at highest priority: {newl.pop(0)}")

def using_builtin(l):
    pq=queue.PriorityQueue()
    for i in l:               #here we are using built-in approach for priority queue
        pq.put(i)

    for i in range(len(l)):
        print(f"Current value at highest priority: {pq.get()}")


def using_tuple(l):
    newl=[]
    for i in range(len(l)):
        p=int(input(f'At what priority u want to assign to {l[i]}: '))
        newl.append((p,l[i]))
    newpq=sorted(newl,reverse=True)             #here we are assigning priority in reverse order i.e higher the value higher the priority
   # print(newpq)
    for i in range(len(l)):
        print(f"Current value at highest priority: {newpq.pop(0)}")


if __name__=="__main__":
    l=[65,4,12,7,3,8,91,12,55,10]
    print('Using tuple: ')
    using_tuple(l)
    print()
    print()
    print('Using list: ')
    using_list(l)
    print()
    print()
    print('Using built-in method: ')
    using_builtin(l)
