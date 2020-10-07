try:
    # a = array
    def insertion_sort(a):
        for i in range(1, len(a)):
            k = a[i]  # k = key
            j = i - 1
            while j >= 0 and k < a[j]:
                a[j + 1] = a[j]
                j -= 1
            a[j + 1] = k
    if __name__ == "__main__":
        n = int(input("Enter the number of elements in the array: "))
        lst = list(map(int, input("\nEnter the numbers : ").strip().split()))[:n]
        print("Before sorted: ", end="\n")
        print(lst)
        insertion_sort(lst)
        print("After sorting: ", end="\n")
        print(lst)
except EOFError as e:
    print(end="")

# end code
# contributer -> souvick roy