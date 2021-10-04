<h1 align = center>Patience Sort</h1>

## Problem statement

Write a program for *Patience sort* 
</br> </br>

### About

In computer science, *Patience sorting* is a sorting algorithm inspired by and named after, the card game patience. </br>

This game begins with a shuffled deck of cards. These cards are dealt one by one into a sequence of piles on the table, according to the following rules: </br>

- Initially, there are no piles. 
- The first card dealt forms a new pile consisting of the single card.
- Each subsequent card is placed on the leftmost existing pile whose top card has a value greater than or equal the new card's value, or to the right of all of the existing piles, thus forming a new pile.
- When there are no more cards remaining to deal, the game ends. </br>

This card game is turned into a two-phase sorting algorithm, as follows:
- Given an array of n elements from some totally ordered domain, consider this array as a collection of cards.
- Simulate the patience sorting game. 
- When the game is over, recover the sorted sequence by repeatedly picking off the minimum visible card.
- In other words, perform a k-way merge of the p piles, each of which is internally sorted. 

</br>

### *Note*: A variant of the algorithm efficiently computes the length of a longest increasing subsequence in a given array. </br> Checkout the code for better understanding.

</br> </br>

### Sample Input-1
```
4
-21 22 1 0
```

### Sample Ouput
```
The sorted array is: -21 0 1 22
```
</br>

### Sample Input-2
```
10
4 3 5 1 4 7 9 8 0 -1
```

### Sample Ouput
```
The sorted array is: -1 0 1 3 4 4 5 7 8 9
```
</br>

### Contributed by
[*Sarthak Luthra*](https://github.com/sarthak-21)