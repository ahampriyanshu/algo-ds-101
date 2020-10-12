

import java.util.*;

public class TrieDataStructure { 
            
    //trie node defination
    static class TrieNode 
    { 
        TrieNode[] children = new TrieNode[26]; 
       
        boolean isEndOfWord; 
          
        TrieNode(){ 
            isEndOfWord = false; 
            for (int i = 0; i < 26; i++) 
                children[i] = null; 
        } 
    }; 
       
     
      
    static void insert(String key) 
    { 
        int level; 
        int length = key.length(); 
        int index; 
       
        TrieNode p = root; 
       
        for (level = 0; level < length; level++) 
        { 
            index = key.charAt(level) - 'a'; 
            if (p.children[index] == null) 
                p.children[index] = new TrieNode(); 
       
            p = p.children[index]; 
        } 
       
        p.isEndOfWord = true; 
    } 
       
    static boolean search(String key) 
    { 
        int level; 
        int length = key.length(); 
        int index; 
        TrieNode p = root; 
       
        for (level = 0; level < length; level++) 
        { 
            index = key.charAt(level) - 'a'; 
       
            if (p.children[index] == null) 
                return false; 
       
            p = p.children[index]; 
        } 
       
        return (p != null && p.isEndOfWord); 
    } 
       
    static TrieNode root; 
    public static void main(String args[]) 
    {  
        String keys[] = {"a","hello","not","news","apple","no"}; 

        root = new TrieNode(); 
        
        for (int i = 0; i < keys.length ; i++) 
            insert(keys[i]); 
        
        if(search("no") == true) 
            System.out.println("Present"); 
        else System.out.println("Absent"); 
          
        if(search("news") == true) 
            System.out.println("Present"); 
        else System.out.println("Absent");
          
        if(search("trie") == true) 
            System.out.println("Present"); 
        else System.out.println("Absent"); 
           
         
    } 
} 