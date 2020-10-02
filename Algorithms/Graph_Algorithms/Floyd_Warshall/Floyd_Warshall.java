package Algorithms.Graph_Algorithms.Floyd_Warshall;

public class Floyd_Warshall {

    private int INF = Integer.MAX_VALUE;

    /** Number of nodes. Ex: 7 */
    private int nodes = 7;

    /** Edge matrix (INF if not exist edge) */
    private int[][] edges = { { INF, 2, INF, 1, INF, INF, INF }, { INF, INF, INF, 3, 10, INF, INF },
            { 4, INF, INF, INF, INF, 5, INF }, { INF, INF, 2, INF, 2, 8, 4 }, { INF, INF, INF, INF, INF, INF, 6 },
            { INF, INF, INF, INF, INF, INF, INF }, { INF, INF, INF, INF, INF, 1, INF } };

    /** Warshall - Path */
    private boolean[][] warshallP = new boolean[nodes][nodes];

    public void warshall() {
        int i, j, k;

        // Adjacency matrix into warshallP
        for (i = 0; i < nodes; i++)
            for (j = 0; j < nodes; j++)
                warshallP[i][j] = (edges[i][j] != INF);

        // Iterate
        for (k = 0; k < nodes; k++)
            for (i = 0; i < nodes; i++)
                for (j = 0; j < nodes; j++)
                    warshallP[i][j] = (warshallP[i][j] || (warshallP[i][k] && warshallP[k][j]));
    }

}