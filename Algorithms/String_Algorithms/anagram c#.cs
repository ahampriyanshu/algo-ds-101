
using System;
class Anagrams {
    
    static bool isAnagram(string a, string b){
    
        if (a.Length != b.Length) return false;
        
        a = a.ToLower();
        b = b.ToLower();
        
        char[] firstWordArr = a.ToCharArray();
        foreach(char c in b){
            for(int i = 0; i < firstWordArr.Length; i++){
                if (c == firstWordArr[i]){
                    firstWordArr[i] = ' ';
                    break;
                }
            }
        }
        foreach(char c in firstWordArr){
            if (c != ' ') return false;
        }
        
        return true;
    }
        
    static void Main()
    {
        string firstWord = Console.ReadLine();
        string secondWord = Console.ReadLine();
            
        bool answer = isAnagram(firstWord, secondWord);
        Console.WriteLine( (answer) ? "Anagrams" : "Not Anagrams" );
    }

}
