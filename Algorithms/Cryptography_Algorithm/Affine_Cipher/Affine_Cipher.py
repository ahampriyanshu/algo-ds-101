'''
In the affine cipher the letters of an alphabet of size m are first mapped to the integers in the range 0 … m − 1. 
It then uses modular arithmetic to transform the integer that each plaintext letter corresponds to into another 
integer that correspond to a ciphertext letter.

ENCYPTION 
E(x) = (a*x + b) % 26
DECRYPTION
D(x) = a^-1(x - b) % 26
where a^-1 is modular multiplicative inverse of a
'''

# custom constants 
''' these are the custom constants which can be edited'''
a = 5
b = 10



'''
    encryptMessage: encrypt the given text using affine ciper

    param text: the text which need to pe encrypted
    type test: str
    param func: custom func can be passed by the user which will be used in affine cipher
    type func: function 
    default func: x: a*x + b
'''
def encryptMessage(text, func = lambda x: a*x + b):

    encrypted_text = ""
    mod = 26
    for character in text:


        # to check the case and convert the character in that specific case
        # else if characte is not a alphabet don't change it
        if character.isupper():
            ascii_val = ord(character) - ord('A')
            new_ascii_val = func(ascii_val) % mod
            new_ascii_val += ord('A')

        elif character.islower():
            ascii_val = ord(character) - ord('a')
            new_ascii_val = func(ascii_val) % mod
            new_ascii_val += ord('a')
        else:
            ascii_val = ord(character)
            new_ascii_val = ascii_val

        encrypted_text = encrypted_text + chr(new_ascii_val)

    
    return encrypted_text


# finding modular multiplicative inverse of a
inv_a = a
for i in range(26):
    if i*a%26 == 1: inv_a = i; break



'''
   decryptMessage: decrypt the given text using affine ciper

    param text: the encrypted text which need to pe decrypted
    type test: str
    param func: custom func can be passed by the user which will be used in affine cipher
    type func: function 
    default func: x: inv_a*(x - b)
'''
def decryptMessage(text, func = lambda x: inv_a*(x - b)):

    decrypted_text = ""
    mod = 26
    for character in text:


        # to check the case and convert the character in that specific case
        # else if characte is not a alphabet don't change it
        if character.isupper():
            ascii_val = ord(character) - ord('A')
            new_ascii_val = func(ascii_val) % mod
            new_ascii_val += ord('A')

        elif character.islower():
            ascii_val = ord(character) - ord('a')
            new_ascii_val = func(ascii_val) % mod
            new_ascii_val += ord('a')
        else:
            ascii_val = ord(character)
            new_ascii_val = ascii_val

        decrypted_text = decrypted_text + chr(new_ascii_val)

    
    return decrypted_text


#--------------------------------------------------------------------

def  main():
    
    text = input("enter your text: ")

    # custom function can also be used 
    # eg. encryptMessage(text, func = lambda x: 7*x + 11 ) 
    cipher = encryptMessage(text)
    print("encrypted text : " + cipher)
    print("decypted text : " + decryptMessage(cipher))

    
main()