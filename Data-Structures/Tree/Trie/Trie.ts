class TrieNodeTS
{
    content: string | null = null; 
    isEnd: boolean = false; 
    count: number = 0;  
    childList: Array<TrieNodeTS> | null = null; 

    /* Constructor */
    constructor(c: string)
    {
        this.childList = [];
        this.isEnd = false;
        this.content = c;
        this.count = 0;
    }  

    subNode = (c: string) =>
    {
        if (this.childList != null)
            for (let eachChild of this.childList)
                if (eachChild.content === c)
                    return eachChild;
        return null;
    }
}


class TrieTS
{

    root: TrieNodeTS | null | undefined;

     /* Constructor */
    constructor()
    {
        this.root = new TrieNodeTS(' '); 
    }

     /* Function to insert word */
    insert = (word: string) =>
    {
        if (this.search(word) === true) 
            return;        

        let current = this.root; 
        for (let ch of word.split(''))
        {
            let child: TrieNodeTS | null | undefined = current?.subNode(ch);
            if (child != null)
                current = child;
            else 
            {
                 current?.childList?.push(new TrieNodeTS(ch));
                 current = current?.subNode(ch);
            }
            if(current) {
                current.count += 1;
            }
        }

        if(current) {
            current.isEnd = true;
        }
    }

    /* Function to search for word */
    search = (word: string) =>
    {
        let current = this.root;  
        for (let ch of word.split(''))
        {
            if (current?.subNode(ch) === null)
                return false;
            else
                current = current?.subNode(ch);
        }      

        if (current?.isEnd == true) 
            return true;

        return false;
    }


    test = () =>
    {            
        /* Creating object of AATree */

        const t = new TrieTS(); 
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

const trieTestTs: TrieTS = new TrieTS();
trieTestTs.test();