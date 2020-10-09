import sys

def create_key(msg, key):
    key = list(key)
    if len(msg) == len(key):
        return key
    elif len(key) < len(msg):
        n = (len(msg) // len(key)) + 1
        key = key * n
        return ''.join(key[:len(msg)])

def encrypt(msg, key):
    cipher_text = []
    x = 0
    key = create_key(msg, key)

    for i in range(0, len(msg)):
        x = (ord(msg[i]) + ord(key[i])) % 26
        x += ord('A')
        cipher_text.append(chr(x))
    return cipher_text

def decrypt(msg, key):
    key = create_key(msg, key)
    plain_text = []

    for i in range(0, len(msg)):
        x = (ord(msg[i]) - ord(key[i]) + 26) % 26
        x += ord('A')
        plain_text.append(chr(x))
    return plain_text

if __name__ == '__main__':
    print("\t\tVigenere Cipher Application")
    print("\t"+"=" * 41)
    print("Please choose an option below:\n")
    print("1. Encrypt")
    print("2. Decrypt")
    print("3. Exit")
    while True:
        opt = input("Selection: ")
        try:
            opt = int(opt)
            if opt == 1:
                msg = input("Please provide your message to encrypt: ")
                msg = msg.upper().replace(" ", "")
                key = input("Please provide your key: ")
                key = key.upper().replace(" ", "")
                cipher_text = encrypt(msg, key)
                print("Encrypted message:", "".join(cipher_text))
            elif opt == 2:
                msg = input("Please provide your message to decrypt: ")
                msg = msg.upper().replace(" ", "")
                key = input("Please provide your key: ")
                key = key.upper().replace(" ", "")
                plain_text = decrypt(msg, key)
                print("Encrypted message:", "".join(plain_text))
            elif opt == 3:
                sys.exit()
            else:
                print("Incorrect option, try again")
                continue
        except ValueError:
            print("Incorrect option, try again")
            continue
