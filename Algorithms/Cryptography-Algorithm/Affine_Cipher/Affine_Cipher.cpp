// In the affine cipher the letters of an alphabet of size m are first mapped to the integers in the range 0 … m − 1. 
// It then uses modular arithmetic to transform the integer that each plaintext letter corresponds to into another 
// integer that correspond to a ciphertext letter.

// ENCYPTION 
// E(x) = (a*x + b) % 26
// DECRYPTION
// D(x) = a^-1(x - b) % 26
// where a^-1 is modular multiplicative inverse of a




#include<bits/stdc++.h> 
using namespace std; 
  
int a = 5; 
int b = 8; 
int inv_a;


// encryptMessage: encrypt the given text using affine ciper

// param text: the text which need to pe encrypted
// type test: string
// param func: custom func can be passed by the user which will be used in affine cipher
// type func: function (int) ->int
// default func: x: a*x + b
  
string encryptMessage(string text, int (*func)(int)=NULL) 
{ 

    string encrypted_text = "";
    if(func==NULL){
        func = [](int x){   return a*x + b; };
    }

    int mod = 26;
    for(const char character : text)
    {

        //to check the case and convert the character in that specific case
        //else if characte is not a alphabet don't change it
        int ascii_val, new_ascii_val;
        if (isupper(character))
        {
            ascii_val = int(character) - int('A');
            new_ascii_val = func(ascii_val) % mod;
            new_ascii_val += int('A');
        }

        else if (islower(character))
        {   
            ascii_val = int(character) - int('a');
            new_ascii_val = func(ascii_val) % mod;
            new_ascii_val += int('a');
        }

        else 
        {
            ascii_val = int(character);
            new_ascii_val = ascii_val;
        }

        encrypted_text = encrypted_text + char(new_ascii_val);
    }
    
    return encrypted_text;

} 


  
// decryptMessage: decrypt the given text using affine ciper

//  param text: the encrypted text which need to pe decrypted
//  type test: str
//  param func: custom func can be passed by the user which will be used in affine cipher
//  type func: function 
//  default func: x: inv_a*(x - b)
  
string decryptMessage(string text, int (*func)(int)=NULL) 
{ 
    
// finding modular multiplicative inverse of a
    for(int i = 0; i < 26; i++)
    {
        if((i*a)%26 == 1){   inv_a = i; break;   }
    }

    string decyrpted_text = "";
    if(func==NULL){
        func = [](int x){   
            return inv_a*(x - b); 
        };
    }

    int mod = 26;
    for(const char character : text)
    {

        //to check the case and convert the character in that specific case
        //else if characte is not a alphabet don't change it
        int ascii_val, new_ascii_val;
        if (isupper(character))
        {
            ascii_val = int(character) - int('A');
            new_ascii_val = func(ascii_val) % mod;
            new_ascii_val = new_ascii_val<0 ? mod + new_ascii_val : new_ascii_val;
            new_ascii_val += int('A');
        }

        else if (islower(character))
        {   
            ascii_val = int(character) - int('a');
            new_ascii_val = func(ascii_val) % mod;
            new_ascii_val = new_ascii_val<0 ? mod + new_ascii_val : new_ascii_val;
            new_ascii_val += int('a');
        }

        else 
        {
            ascii_val = int(character);
            new_ascii_val = ascii_val;
        }

        decyrpted_text = decyrpted_text + char(new_ascii_val);
    }
    
    return decyrpted_text;

} 
  

int main(void) 
{ 
    string msg;
    getline(cin,msg); 

    // custom function can also be used   
    string cipherText = encryptMessage(msg); 
    cout << "Encrypted Message is : " << cipherText<<endl; 
    cout << "Decrypted Message is: " << decryptMessage(cipherText); 
  
    return 0; 
} 
