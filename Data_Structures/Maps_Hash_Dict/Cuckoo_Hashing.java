import java.util.*; 
  
class Cuckoo_Hashing
{ 
static int MAXN = 11; 
static int ver = 2; 
static int [][]hashtable = new int[ver][MAXN]; 
  

static int []pos = new int[ver]; 
  
static void initTable() 
{ 
    for (int j = 0; j < MAXN; j++) 
        for (int i = 0; i < ver; i++) 
            hashtable[i][j] = Integer.MIN_VALUE; 
} 
  
static int hash(int function, int key) 
{ 
    switch (function) 
    { 
        case 1: return key % MAXN; 
        case 2: return (key / MAXN) % MAXN; 
    } 
    return Integer.MIN_VALUE; 
} 
static void place(int key, int tableID, int cnt, int n) 
{ 
    
    if (cnt == n) 
    { 
        System.out.printf("%d unpositioned\n", key); 
        System.out.printf("Cycle present. REHASH.\n"); 
        return; 
    } 
    for (int i = 0; i < ver; i++) 
    { 
        pos[i] = hash(i + 1, key); 
        if (hashtable[i][pos[i]] == key) 
        return; 
    } 
    if (hashtable[tableID][pos[tableID]] != Integer.MIN_VALUE) 
    { 
        int dis = hashtable[tableID][pos[tableID]]; 
        hashtable[tableID][pos[tableID]] = key; 
        place(dis, (tableID + 1) % ver, cnt + 1, n); 
    } 
    else 
    hashtable[tableID][pos[tableID]] = key; 
} 
static void printTable() 
{ 
    System.out.printf("Final hash tables:\n"); 
  
    for (int i = 0; i < ver; i++, System.out.printf("\n")) 
        for (int j = 0; j < MAXN; j++) 
            if(hashtable[i][j] == Integer.MIN_VALUE)  
                System.out.printf("- "); 
            else
                System.out.printf("%d ", hashtable[i][j]); 
  
    System.out.printf("\n"); 
} 
  
static void cuckoo(int keys[], int n) 
{ 
    initTable(); 
    for (int i = 0, cnt = 0; i < n; i++, cnt = 0) 
        place(keys[i], 0, cnt, n); 
    printTable(); 
} 
public static void main(String[] args)  
{ 
    int keys_1[] = {20, 50, 53, 75, 100,  
                    67, 105, 3, 36, 39}; 
  
    int n = keys_1.length; 
  
    cuckoo(keys_1, n); 
    int keys_2[] = {20, 50, 53, 75, 100,  
                    67, 105, 3, 36, 39, 6}; 
  
    int m = keys_2.length; 
  
    cuckoo(keys_2, m); 
} 
}