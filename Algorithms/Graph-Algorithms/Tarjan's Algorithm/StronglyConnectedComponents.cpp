#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> disc, low, instack;
vector<vector<int>> ans;
void DFS(int u, vector<int> adj[], stack<int> &st)
{
    t += 1;
    disc[u] = t;
    low[u] = t;
    instack[u] = 1;
    st.push(u);
    for (int k : adj[u])
    {
        if (disc[k] == -1)
        {
            DFS(k, adj, st);
            low[u] = min(low[u], low[k]);
        }
        else
        {
            if (instack[k])
            {
                low[u] = min(low[u], disc[k]);
            }
        }
    }
    if (disc[u] == low[u])
    {
        vector<int> a;
        while (!st.empty() and st.top() != u)
        {
            a.push_back(st.top());
            instack[st.top()] = 0;
            st.pop();
        }
        a.push_back(st.top());
        instack[st.top()] = 0;
        st.pop();
        sort(a.begin(), a.end());
        ans.push_back(a);
    }
}
vector<vector<int>> tarjans(int V, vector<int> adj[])
{
    t = 0;
    disc = vector<int>(V, -1);
    low = vector<int>(V, -1);
    instack = vector<int>(V, 0);
    ans.clear();
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
        {
            DFS(i, adj, st);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<vector<int>> ptr = tarjans(V, adj);

    for (int i = 0; i < ptr.size(); i++)
    {
        for (int j = 0; j < ptr[i].size(); j++)
        {
            if (j == ptr[i].size() - 1)
                cout << ptr[i][j];
            else
                cout << ptr[i][j] << " ";
        }
        cout << ',';
    }
    cout << endl;
    return 0;
}
