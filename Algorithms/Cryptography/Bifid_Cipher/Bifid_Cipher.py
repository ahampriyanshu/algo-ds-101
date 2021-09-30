 
"""
@author: Abhinav Tiwari

@github: abhinav-idle
"""

"""
Bifid Cipher was invented in 1901 by Felix Delastelle.

Bifid cipher is a cipher in which we combine polybius 
square with transposition and fractionation i.e 
we use regular system to shift the letters of input-text
so that the cipher-text constitutes
of permutaion of different plaintext(transposition) as in 
here we replace each letter of input text with respect to 
it co-ordinates in polybius square (fractionation).
the co-ordinates are stored in row by column arrays 
respectively.
After performing these steps for every letter in input text
we have two arrays of equal length constituting of rows and 
columns of each letter, we then concatinate both the arrays
making one array, then we make couples of two and get the 
character according to the polybius square and concatinate 
each character to the encrypted text.
Voila, we have done bifid encryption, to cross verify you can 
decrypt the encrypted message to get back the originat text, by 
reverting each step and using the same polybius square.


In this cipher I'll use a custom 8x8 polybis square to 
cover complex encryption/decryption that includes any 
alpha-numeric combination of the following characters i.e 
        A-Z, a-z, 0-9, ?, @
One can use their own customized polybius square to 
encrypt even more complex input text.
"""

def find_pos(polybius_square, character):
    #returns the co-ordinates of character according to polybius square created as a 
    #tuple of co-ordinates, indexing is done from 1 and not from 0.
    
    for i in range(8):
        
        #to avoid error we've used try exceplt block, as index function raises ValueError 
        #when elemnt is not found in list.
        
        try:
            j = polybius_square[i].index(character)
            return i + 1, j + 1
        
        except ValueError:
            pass

def get_word(a, b, polybius_square):
    
    #returns the character present at (a - 1, b - 1) co-ordinate
    #indexing is from 1 so, we're substracting 1 to get actual co-ordinates.
    
    return polybius_square[a-1][b-1]   
     
def create_polybius_square():
    
    #create and return polybius square as a list
    
    arr = []
    num = 48    #for numeric characters 0-9.
    upper_case = 63    #for uppercase alphabets A-Z and ?,@.
    lower_case = 97    #for lowercase alphabets a-z. 
    
    for i in range(8):
        
        sub_arr = []
        cnt = 0
        
        while(cnt<8):
        
            if num<=57 and cnt<8:
                sub_arr.append(chr(num))
                num += 1 
                cnt += 1
            
            if upper_case<=90 and cnt<8:
                sub_arr.append(chr(upper_case))
                upper_case += 1
                cnt+=1
                
            if lower_case<=122 and cnt<8:
                sub_arr.append(chr(lower_case))
                lower_case += 1
                cnt+=1
            
        arr.append(sub_arr)
    
    return arr

def bifid_encryption(polybius_square, text):
    #implementing bifid-encryption
    
    #to store co-ordinates
    row = []
    column = []

    for letter in text:
        i,j = find_pos(polybius_square, letter)
        row.append(i)
        column.append(j)

    array = []    
    array.extend(row)
    array.extend(column)

    encrypted_text = ""
    
    for i in range(0,len(array),2):
        character = get_word(array[i], array[i+1], polybius_square)
        encrypted_text += character

    return encrypted_text   
 
def decryption(polybius_square, encrypted_text):    
    #decrypt message
    
    array = []
    for text in encrypted_text:
        array.extend(list(find_pos(polybius_square,text)))

    row  = array[:len(array)//2]
    column  = array[len(array)//2:]

    original_text = ""
    
    for i in range(len(row)):
        original_text += get_word(row[i],column[i],polybius_square)
    
    return original_text    


def main():
    
    #Enter text to encrypt

    text = input()

    #created polybius square
    polybius_square = create_polybius_square()

    print("Encrypted text : ",bifid_encryption(polybius_square, text))
    print("Original text : ",decryption(polybius_square, bifid_encryption(polybius_square, text)))

main()
