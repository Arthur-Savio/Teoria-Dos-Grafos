#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> my_pair;

void add_edge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void print_edges(vector<int> parent, int n)
{
    for (int i = 1; i < n; ++i)
        cout << parent[i] << " - " << i << endl;
}

void prim(vector<pair<int, int>> adj[], int V)
{
    priority_queue<my_pair, vector<my_pair>, greater<my_pair>> pq;

    int src = 0;

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> in_mst(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        in_mst[u] = true;
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (in_mst[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    print_edges(parent, V);
}

int main()
{
    int V = 5;
    vector<my_pair> adj[V];

    add_edge(adj, 0, 1, 4);
    add_edge(adj, 0, 7, 8);
    add_edge(adj, 1, 2, 8);
    add_edge(adj, 1, 7, 11);
    add_edge(adj, 2, 3, 7);

    prim(adj, V);

    return 0;
}
