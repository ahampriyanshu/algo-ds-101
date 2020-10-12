def vignereCipher(plain_text, key):
    plain_text_length = len(plain_text)
    key_length = len(key)
    j = 0
    cipher = ''
    for i in range(plain_text_length):
        if(j == key_length):
            j = 0
        cipher_text = (ord(plain_text[i])+ ord(key[j])) % 26
        j+=1
        cipher += chr(cipher_text+65)
    return cipher

def decryptVignereCipher(cipher_text, key):
    key_length = len(key)
    decrpted_text = ''
    j = 0
    for i in range(len(cipher_text)): 
        if(j == key_length):
            j = 0
        decrpt = (ord(cipher_text[i]) - ord(key[j]) + 26) % 26
        j+=1
        decrpted_text += chr(decrpt+65)
    return decrpted_text
        
    
if __name__ == "__main__":
    plain_text = "PLAINTEXT"
    key = "KEY"
    encrypted_text = vignereCipher(plain_text, key)
    print("Cipher text " + encrypted_text)
    decrpted_text = decryptVignereCipher(encrypted_text, key)
    print("Decrypt text " + decrpted_text)