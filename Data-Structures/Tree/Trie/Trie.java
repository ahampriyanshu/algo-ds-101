import java.util.*;

 

class TrieNode 
{
    char content; 
    boolean isEnd; 
    int count;  
    LinkedList<TrieNode> childList; 

    /* Constructor */
    public TrieNode(char c)
    {
        childList = new LinkedList<TrieNode>();
        isEnd = false;
        content = c;
        count = 0;
    }  

    public TrieNode subNode(char c)
    {
        if (childList != null)
            for (TrieNode eachChild : childList)
                if (eachChild.content == c)
                    return eachChild;
        return null;
    }
}


public class Trie
{

    private TrieNode root;

     /* Constructor */
    public Trie()
    {
        root = new TrieNode(' '); 
    }

     /* Function to insert word */
    public void insert(String word)
    {
        if (search(word) == true) 
            return;        

        TrieNode current = root; 
        for (char ch : word.toCharArray() )
        {
            TrieNode child = current.subNode(ch);
            if (child != null)
                current = child;
            else 
            {
                 current.childList.add(new TrieNode(ch));
                 current = current.subNode(ch);
            }
            current.count++;
        }

        current.isEnd = true;
    }

    /* Function to search for word */
    public boolean search(String word)
    {
        TrieNode current = root;  
        for (char ch : word.toCharArray() )
        {
            if (current.subNode(ch) == null)
                return false;
            else
                current = current.subNode(ch);
        }      

        if (current.isEnd == true) 
            return true;

        return false;
    }


    public static void main(String[] args)
    {            

        @SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);

        /* Creating object of AATree */

        Trie t = new Trie(); 
        System.out.println("Trie Test\n");          
        char ch;

        /*  Perform tree operations  */
        do    
        {

            System.out.println("\nTrie Operations\n");

            System.out.println("1. insert ");
            System.out.println("2. search");

 

            int choice = scan.nextInt();            
            switch (choice)
            {

            case 1 : 

                System.out.println("Enter string element to insert");

                t.insert( scan.next() );                     

                break;                          

            case 2 : 

                System.out.println("Enter string element to search");
                System.out.println("Search result : "+ t.search( scan.next() ));
                break;                                          

            default : 
                System.out.println("Wrong Entry \n ");
                break;   

            }

 

            System.out.println("\nDo you want to continue (Type y or n) \n");
            ch = scan.next().charAt(0);                        
        } while (ch == 'Y'|| ch == 'y');               
    }
}    