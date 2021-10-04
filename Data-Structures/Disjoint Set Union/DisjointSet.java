public class DisjointSet {
    
    // https://cp-algorithms.com/data_structures/disjoint_set_union.html

    int parent[];
    int depth[];
    int n;

    DisjointSet(int n)
    {
        this.n = n;
        parent = new int[n];
        depth = new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            depth[i] = 0;
        }
    }

    int findSet(int i)
    {
        if(parent[i]==i)
            return i;
        return (parent[i] = findSet(parent[i]));
    }

    void union(int a,int b)
    {
        int x = findSet(a);
        int y = findSet(b);
        if(x!=y)
        {
            if(depth[x]<depth[y])
            {
                int t = x;
                x = y;
                y = t;
            }
            parent[y] = x;
            if(depth[y]==depth[x])
                depth[x]++;
        }
    }
}
