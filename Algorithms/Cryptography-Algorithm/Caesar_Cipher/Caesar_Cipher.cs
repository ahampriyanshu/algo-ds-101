using System;

class Program
{
    /// <summary>
    /// Shifts every character of a given string by a specified amount
    /// and returns the shifted string.
    /// </summary>
    private static string CaesarCipher(string text, int shiftAmount)
    {
        char[] characters = text.ToCharArray();

        for (int i = 0; i < characters.Length; i++)
        {
            char character = characters[i];

            if (char.IsLetter(character) == false) { continue; }

            int offsetCharacter = (char.IsLower(character) ? 'a' : 'A');

            characters[i] = (char)((((character + shiftAmount) - offsetCharacter) % 26) + offsetCharacter);
        }

        return string.Join(string.Empty, characters);
    }

    /// <summary>
    /// Encrypts the given text using the Caesar cipher.
    /// </summary>
    private static string Encrypt(string text, int shiftAmount)
    {
        return Program.CaesarCipher(text, shiftAmount);
    }

    /// <summary>
    /// Decrypts the given text using the Caesar cipher.
    /// </summary>
    private static string Decrypt(string text, int shiftAmount)
    {
        return Program.CaesarCipher(text, (26 - shiftAmount));
    }

    /// <summary>
    /// Main application function.
    /// </summary>
    static void Main()
    {
        bool shouldEncrpyt;
        int shiftAmount;
        string textToProcess, userInput;
        
        Console.WriteLine("Do you want to [E]ncrypt or [D]ecrypt? (Enter \"E\" or \"D\"):");
        userInput = Console.ReadLine().ToLower();
        
        if ((userInput != "e") && (userInput != "d")) { Program.ExitAfterInvalidInput(); }
        
        shouldEncrpyt = (userInput == "e");

        Console.WriteLine(string.Format("Enter the text to {0}:", (shouldEncrpyt ? "encrypt" : "decrypt")));
        userInput = Console.ReadLine();
        
        if (string.IsNullOrWhiteSpace(userInput)) { Program.ExitAfterInvalidInput(); }
        
        textToProcess = userInput;

        Console.WriteLine("Enter an integer for the shift amount (key):");
        userInput = Console.ReadLine();
        
        if (int.TryParse(userInput, out shiftAmount) == false) { Program.ExitAfterInvalidInput(); }

        string result = (shouldEncrpyt ? Program.Encrypt(textToProcess, shiftAmount) : Program.Decrypt(textToProcess, shiftAmount));
        
        Console.WriteLine();
        Console.WriteLine(string.Format("Result: {0}", result));
    }
    
    /// <summary>
    /// Informs the user that an invalid value has been entered and exits the program.
    /// </summary>
    private static void ExitAfterInvalidInput()
    {
        Console.WriteLine("You've entered an invalid value. Exiting...");
        Environment.Exit(1);
    }
}
