<script>

	// ArrayList to store tree
	let g;
	let memo, lev, log;

	// Pre-processing to calculate values of memo[][]
	function dfs(u, p)
	{

		// Using recursion formula to calculate
		// the values of memo[][]
		memo[u][0] = p;
		for (let i = 1; i <= log; i++)
			memo[u][i] = memo[memo[u][i - 1]][i - 1];
		for (let v = 0; v < g[u].length; v++) {
			if (g[u][v] != p) {

				// Calculating the level of each node
				lev[g[u][v]] = lev[u] + 1;
				dfs(g[u][v], u);
			}
		}
	}

	// Function to return the LCA of nodes u and v
	function lca(u, v)
	{
		// The node which is present farthest
		// from the root node is taken as u
		// If v is farther from root node
		// then swap the two
		if (lev[u] < lev[v]) {
			let temp = u;
			u = v;
			v = temp;
		}

		// Finding the ancestor of u
		// which is at same level as v
		for (let i = log; i >= 0; i--) {
			if ((lev[u] - Math.pow(2, i)) >= lev[v])
				u = memo[u][i];
		}

		// If v is the ancestor of u
		// then v is the LCA of u and v
		if (u == v)
			return u;

		// Finding the node closest to the root which is
		// not the common ancestor of u and v i.e. a node
		// x such that x is not the common ancestor of u
		// and v but memo[x][0] is
		for (let i = log; i >= 0; i--) {
			if (memo[u][i] != memo[v][i]) {
				u = memo[u][i];
				v = memo[v][i];
			}
		}

		// Returning the first ancestor
		// of above found node
		return memo[u][0];
	}
	
	// Number of nodes
	let n = 9;
	g = new Array(n + 1);

	// log(n) with base 2
	log = Math.ceil(Math.log(n) / Math.log(2));
	memo = new Array(n + 1);

	// Stores the level of each node
	lev = new Array(n + 1);
	lev.fill(0);

	// Initialising memo values with -1
	for (let i = 0; i <= n; i++)
	{
		memo[i] = new Array(log+1);
		for (let j = 0; j < log+1; j++)
		{
			memo[i][j] = -1;
		}
	}
	for (let i = 0; i <= n; i++)
	g[i] = [];

	// Add edges
	g[1].push(2);
	g[2].push(1);
	g[1].push(3);
	g[3].push(1);
	g[1].push(4);
	g[4].push(1);
	g[2].push(5);
	g[5].push(2);
	g[3].push(6);
	g[6].push(3);
	g[3].push(7);
	g[7].push(3);
	g[3].push(8);
	g[8].push(3);
	g[4].push(9);
	g[9].push(4);
	dfs(1, 1);
	document.write("The LCA of 6 and 9 is " + lca(6, 9) + "</br>");
	document.write("The LCA of 5 and 9 is " + lca(5, 9) + "</br>");
	document.write("The LCA of 6 and 8 is " + lca(6, 8) + "</br>");
	document.write("The LCA of 6 and 1 is " + lca(6, 1));
	
</script>
