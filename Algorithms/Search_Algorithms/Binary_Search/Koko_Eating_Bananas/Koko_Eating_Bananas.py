# -*- coding: utf-8 -*-
"""
Created on Wed Oct 14 23:34:35 2020

@author: Abhinav Tiwari

Solution to question as per QUESTION.md's
 
    Koko eating bananas
    finds eating rate K bananas/hr 
    So, that she can finish the pile 
    before the guards arrive.
"""
import math


def min_rate(pile,hrs):
    res = 0
    for i in range(len(pile)):
        res += math.ceil(pile[i]/hrs)
    return res    
        
def banana_per_hour(pile,hrs):
    
    if len(pile)==1:
        return math.ceil(pile[0]/hrs)
    
    lo = 1
    hi = max(pile)
    
    value = -986765
    while(lo<hi):
        mid = lo + (hi-lo)//2
        value = min_rate(pile, mid)
        if value<=hrs:
            hi = mid
        else:
            lo = mid + 1
    
    return lo
       
    
    
def main():
    bananas = []
    print("Enter the bananas in pile one by one",end = "\n")
    print("Enter any negative no to quit",end ='\n')
    n = int(input())
    while(n>0):
        bananas.append(n)
        n = int(input())
    H = int(input("Enter hours till the guards arrive:    ")) 
    K = banana_per_hour(bananas, H)
    print("For her to eat all the bananas till the guards arrive, she must eat @ ",K,"bananas per hour")
main()