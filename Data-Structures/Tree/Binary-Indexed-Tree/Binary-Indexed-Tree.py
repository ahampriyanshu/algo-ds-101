# BUILD, UPDATE ,QUERY BINARY INDEXED TREE OR FENWICK TREE


class BITree:
    # Construction of a Binary Indexed Tree
    def __init__(self, a: list):
        n = len(a) + 1
        self.__BIT = [0] * n
        for i in range(1, n):
            self.update(i, a[i - 1])

    def __getitem__(self, i):
        return self.__BIT[i]

    # Always pass by this method to update the BITree
    def update(self, i: int, val: int):
        while i < len(self.__BIT):
            self.__BIT[i] += val
            # The line below makes i to move to the parent node
            i += i & (-i)

    def getSum(self, i: int):
        total = 0
        while i > 0:
            total += self.__BIT[i]
            i -= i & (-i)

        return total


if __name__ == "__main__":
    a = [
        int(i)
        for i in input("Values of separated by commas: ").replace(" ", "").split(",")
    ]
    BIT = BITree(a)

    print("Binary Indexed Tree array:")
    print(", ".join(str(i) for i in BIT))

    print("Press Ctrl+c to exit the loop...")
    while True:
        index = int(input("Get the sum from 1 to : "))
        print(BIT.getSum(index))
