#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> my_pair;

void add_edge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    cout << u << " " << v << " " << wt << endl;
    adj[u].push_back(make_pair(v, wt));
    // adj[v].push_back(make_pair(u, wt));
}

void print_edges(vector<int> parent, int n)
{
    for (int i = 1; i < n; ++i)
        cout << parent[i] << " -> " << i << endl;
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

bool file_exist(string filename)
{
    ifstream f(filename);
    return f.is_open();
}

bool get_file(int argc, char *argv[], ifstream &file)
{
    if (argc <= 1)
    {
        cout << "Missing Arguments ! " << endl;
        return false;
    }
    else if (!file_exist(argv[1]))
    {
        cout << "File " << argv[1] << " not found." << endl;
        cout << "Try Again! " << endl;
        return false;
    }

    file.open(argv[1]);
    return true;
}

int main(int argc, char *argv[])
{
    ifstream file;

    int src, weight, dest, v, e;

    get_file(argc, argv, file);

    file >> v;
    file >> e;

    vector<my_pair> adj[v];

    while (file >> src && file >> dest && file >> weight)
    {
        add_edge(adj, src, dest, weight);
    }

    prim(adj, v);

    return 0;
}
