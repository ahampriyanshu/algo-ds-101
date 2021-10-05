using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    static List<char> characters = "abcdefghijklmnopqrstuvwxyz".ToList();

    // wrap value if it is above n or below zero
    static int wrap(int k, int n)
    {
        int r = k % n;
        return (r < 0) ? r + n : r;
    }

    static string VignereCipher(string plaintext, string key)
    {
        string ciphertext = "";
        for (int i = 0; i < plaintext.Length; i++)
        {
            // get the current key character.
            char keyCharacter = key[i % key.Length];
            // shift value is the index of this character in 'characters'.
            int shift = characters.IndexOf(keyCharacter);

            // index of the plaintext character in the 'characters' array.
            int plaincharNumber = characters.IndexOf(plaintext[i]);
            // shift this index by the shift value, wrapping if it goes over 26.
            int ciphercharNumber = wrap((plaincharNumber + shift), 26);
            // and get the character from this index.
            char cipherchar = characters[ciphercharNumber];

            ciphertext += cipherchar;
        }

        return ciphertext;
    }

    static string VignereDecipher(string ciphertext, string key)
    {
        string plaintext = "";
        for (int i = 0; i < ciphertext.Length; i++)
        {
            // get the current key character.
            char keyCharacter = key[i % key.Length];
            // shift value is the index of this character in 'characters'.
            int shift = characters.IndexOf(keyCharacter);

            // index of the ciphertext character in the 'characters' array.
            int ciphercharNumber = characters.IndexOf(ciphertext[i]);
            // shift this index by the shift value, but in the other direction,
            // wrapping through 26 if it goes under 0.
            int plaincharNumber = wrap((ciphercharNumber - shift), 26);
            // and get the character from this index.
            char plainchar = characters[plaincharNumber];

            plaintext += plainchar;
        }

        return plaintext;
    }

    public static void Main(string[] args)
    {
        string ciphertext = VignereCipher("helloworld", "key");
        Console.WriteLine($"Plaintext: helloworld -> Key: key ->  Ciphertext: {ciphertext}.");

        string plaintext = VignereDecipher("uogtprtso", "pass");
        Console.WriteLine($"Ciphertext: uogtprtso <- Key: pass <- Plaintext: {plaintext}.");
    }
}