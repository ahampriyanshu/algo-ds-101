/**
 * Segment Tree, or Segment Tree, is one of the most used data structures in competitive programming
 * due to its efficiency and versatility in operations of consultation in intervals and updating of elements in the array.
 * It consists of breaking the array into several intervals (segments).
 * Then, based on these intervals, we build a tree where each node stores the sum of the elements in the interval.
 * Complexity: construction - O (n); query & update - O (log n).
 * 
 * @author Ytalo Ramon
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 10
#define CALMIDDLE(a, b)((a + b) / 2)

int build(int *listV, int *listSegment, int startInterv, int endInterv, int posi);

int update(int newValue, int indexUpdate, int *listSegment, int startInterv, int endInterv, int posi);

int getSum(int *listSegment, int findStartIndex, int findEndIndex, int startInterv, int endInterv, int posi);

void show(char *title, int *l, int length);

int main(int argc, char const *argv[]){
    
    // Allocation variable and defined values
    int listValues[MAX] = {15, 2, 6, 9, 10, 1, 156, 7, 88, 65}, listSegmTree[MAX * 4];
    // Set 0 the segment tree in all position 
    memset(listSegmTree, 0, sizeof(int) * MAX * 4);

    // Constructor segment tree
    build(listValues, listSegmTree, 0, MAX, 0);
    show("Array", listValues, MAX);
    show("SegTree", listSegmTree, MAX * 3 + 10);

    printf("Update: idx=0; new_value=4\n");
    listValues[0] = 4;
    update(4, 0, listSegmTree, 0, MAX, 0);
    show("Array", listValues, MAX);
    show("SegTree", listSegmTree, MAX * 3 + 10);

    printf("SUM: start=0; end=4 => %d\n", getSum(listSegmTree, 0, 4, 0, MAX, 0));
    show("Array", listValues, MAX);

    printf("SUM: start=5; end=9 => %d\n", getSum(listSegmTree, 5, 9, 0, MAX, 0));
    show("Array", listValues, MAX);

    printf("Update: idx=6; new_value=899\n");
    listValues[6] = 899;
    update(899, 6, listSegmTree, 0, MAX, 0);
    show("Array", listValues, MAX);
    show("SegTree", listSegmTree, MAX * 3 + 10);

    printf("SUM: start=0; end=9 => %d\n", getSum(listSegmTree, 0, 9, 0, MAX, 0));
    show("Array", listValues, MAX);

    printf("SUM: start=3; end=7 => %d\n", getSum(listSegmTree, 3, 7, 0, MAX, 0));
    show("Array", listValues, MAX);
    
    return 0;
}

int build(int *listV, int *listSegment, int startInterv, int endInterv, int posi){
    if (startInterv == endInterv - 1)
        return listSegment[posi] = listV[startInterv];

    const int middle = CALMIDDLE(startInterv, endInterv),
        sumInterv = build(listV, listSegment, startInterv, middle, posi * 2 + 1) +
                    build(listV, listSegment, middle, endInterv, posi * 2 + 2);

    return listSegment[posi] = sumInterv; 
}

int update(int newValue, int indexUpdate, int *listSegment, int startInterv, int endInterv, int posi){
    if (startInterv == endInterv - 1)
        return listSegment[posi] = newValue;

    const int middle = CALMIDDLE(startInterv, endInterv),
            sumInterv = indexUpdate < middle ? 
                            update(newValue, indexUpdate, listSegment, startInterv, middle, posi * 2 + 1) + listSegment[posi * 2 + 2]:
                            update(newValue, indexUpdate, listSegment, middle, endInterv, posi * 2 + 2) + listSegment[posi * 2 + 1];
                                                
    return listSegment[posi] = sumInterv;
}

int getSum(int *listSegment, int findStartIndex, int findEndIndex, int startInterv, int endInterv, int posi){
    if (findStartIndex >= endInterv || findEndIndex < startInterv)
        return 0;

    if (findStartIndex <= startInterv && endInterv <= findEndIndex + 1)
        return listSegment[posi];

    const int middle = CALMIDDLE(startInterv, endInterv);

    return getSum(listSegment, findStartIndex, findEndIndex, startInterv, middle, posi * 2 + 1) +
            getSum(listSegment, findStartIndex, findEndIndex, middle, endInterv, posi * 2 + 2);
}

void show(char *title, int *l, int length){
    printf("%s\n", title);
    for (int i = 0; i < length; i++) printf("%d ", l[i]);
    printf("\n-----------------\n\n");
}