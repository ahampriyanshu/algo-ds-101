/**
 Binary Index Tree or Fenwick Tree
 It is a data structure that can efficiently update
 elements and calculate prefix sums in a table of numbers.

 There are two types of query that the user can input in this program

 1. Get sum upto ith position
    Format - 1 i
    Ex - 1 5

 2. Update the element at ith position to k
    Format - 2 i k
    Ex - 1 5 2

    SAMPLE INPUT :-
        12
        2 1 1 3 2 3 4 5 6 7 8 9
        3
        1 5
        2 2 6
        1 5

    EXPECTED OUTPUT :-
        9
        14
*/
#include <stdio.h>

//Create BIT in O(n) time
void createBIT(int ftree[], int n) {

    for(int i=1; i<=n; i++) {
        int j = i + (i & (-1*i));
        if(j <= n)
            ftree[j] += ftree[i];
    }
}

//Update the value in the required nodes in Tree in O(log n)
void update(int ftree[], int n, int val, int i) {
    while(i <= n) {
        ftree[i] += val;
        i += (i & (-1*i));
    }
}

//Gives the sum of elements upto ith position in O(log n)
int getSum(int ftree[], int n, int i) {
    int sum = 0;
    while(i != 0) {
        sum += ftree[i];
        i -= (i & (-1*i));
    }
    return sum;
}

int main() {
    int n, query;
    int val, i, type;
    printf("Enter size of Array: ");
    scanf("%d", &n);

    int ftree[n+1];
    int arr[n+1];
    ftree[0] = arr[0] = 0;
    printf("Enter %d elements in array: ", n);
    for(i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
        ftree[i] = arr[i];
    }

    printf("Enter no. of Queries: ");
    scanf("%d", &query);

    createBIT(ftree, n);
    while(query--) {
        printf("Enter Query: ");
        scanf("%d", &type);

        if(type == 1) {
            scanf("%d", &i);
            printf("Sum: %d\n", getSum(ftree, n, i));
        }
        else {
            scanf("%d %d", &i, &val);
            update(ftree, n, val - arr[i], i);
        }
    }
}
