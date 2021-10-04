# -*- coding: utf-8 -*-
import random
from math import gcd

plaintext = (input('Enter the value of text = '))

pt = ""
if (plaintext.isnumeric()) :
    pt = plaintext
else :
    for i in range(0,len(plaintext)):
      pt += str(ord(plaintext[i]))
    print(pt)    

def modInverse(e, phin) : 
    e = e % phin; 
    for d in range(1, phin) : 
        if ((e * d) % phin == 1) : 
            return d
    return 1

import sympy
p=sympy.randprime(1000, 2000) 
q=sympy.randprime(1000, 2000) 

n=p*q

phin=(p-1)*(q-1)
list=[]

for i in range(2,phin):
  if gcd(phin,i)==1:
    list.append(i)

e = random.choice(list) 

d = modInverse(e,phin)

ciphertext = pow(int(pt),e)%n
decrypttext = pow(ciphertext,d)%n

print('n = '+str(n)+' e = '+str(e)+' phi(n) = '+str(phin)+' d = '+str(d)+' cipher text = '+str(ciphertext)+' decrypted text = '+str(decrypttext))
