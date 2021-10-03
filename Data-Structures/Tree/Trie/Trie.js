class TrieNode 
{
    content = null; 
    isEnd = false; 
    count = 0;  
    childList = null; 

    /* Constructor */
    constructor(c)
    {
        this.childList = [];
        this.isEnd = false;
        this.content = c;
        this.count = 0;
    }  

    subNode = (c) =>
    {
        if (this.childList != null)
            for (let eachChild of this.childList)
                if (eachChild.content === c)
                    return eachChild;
        return null;
    }
}


class Trie
{

    root;

     /* Constructor */
    constructor()
    {
        this.root = new TrieNode(' '); 
    }

     /* Function to insert word */
    insert = (word) =>
    {
        if (this.search(word) === true) 
            return;        

        let current = this.root; 
        for (let ch of word.split(''))
        {
            this.child = current.subNode(ch);
            if (this.child != null)
                current = this.child;
            else 
            {
                 current.childList.push(new TrieNode(ch));
                 current = current.subNode(ch);
            }
            current.count++;
        }

        current.isEnd = true;
    }

    /* Function to search for word */
    search = (word) =>
    {
        let current = this.root;  
        for (let ch of word.split(''))
        {
            if (current.subNode(ch) === null)
                return false;
            else
                current = current.subNode(ch);
        }      

        if (current.isEnd == true) 
            return true;

        return false;
    }


    test = () =>
    {            
        /* Creating object of AATree */

        const t = new Trie(); 
        /*  Perform tree operations  */
        t.insert("trie"); 
        t.insert("is");
        t.insert("an"); 
        t.insert("efficient");  
        t.insert("retrieval"); 
        t.insert("structure");
    
        //enter your search word        
        console.log('Is search word `trie` present: ', t.search("trie"));
        console.log('Is search word `tree` present: ', t.search("tree"));
              
    }
}    

const trieTest = new Trie();
trieTest.test();