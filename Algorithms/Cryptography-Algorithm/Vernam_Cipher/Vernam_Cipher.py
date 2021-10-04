#!/usr/bin/env python
import random
import string
from operator import xor
def vernam_enc(msg):
    #Generate Random Key
    randomKey = ''.join([random.choice(string.ascii_letters) for i in range(len(msg))])
    print("Random Key: "+randomKey)
    
    #Convert string to decimal
    convdecimal = []
    for i in range(len(msg)):
        convdecimal.append(str(ord(msg[i])))
    decimal = ' '.join(convdecimal)
	
	#Convert decimal to biner
    convbiner = []
    for i in range(len(convdecimal)):
        convbiner.append(str(bin(int(convdecimal[i]))[2:].zfill(8)))
    biner = ''.join(convbiner)


    #Convert key to decimal
    convkeydecimal = []
    for i in range(len(randomKey)):
        convkeydecimal.append(str(ord(randomKey[i])))
    keydecimal = ' '.join(convkeydecimal)
    
    #Convert key decimal to biner
    convkeybiner = []
    for i in range(len(convkeydecimal)):
        convkeybiner.append(str(bin(int(convkeydecimal[i]))))
    binerkey = ''.join(convkeybiner)


    binermsg =biner.replace("b","")

    binerkey =binerkey.replace("b","")

    #XOR Function
    ciphertext = []
    for i in range(len(binermsg)):
        ciphertext.append(xor(int(binermsg[i]),int(binerkey[i])))
    cipherfix =''.join(map(str,ciphertext))
    splits=[cipherfix[x:x+8] for x in range(0,len(cipherfix),8)]

    #convert biner to decimal
    hexa = []
    for i in range(len(splits)):
        hexa.append(hex(int(splits[i],2)))
        
    #convert hex to desimal
    dec = []
    for i in range(len(hexa)):
        dec.append(int(hexa[i], 16))
    print("Ciphertext-Num : \n"+str(dec))

	#final convert to text
    teks = []
    for i in range(len(dec)):
        teks.append(chr(dec[i]))
    print("Ciphertext : \n"+''.join(teks))
    

def main():
    print("Vernam Cipher")
    msg = input("Enter Text : ")
    vernam_enc(msg)
if __name__ == '__main__':
    	main()
