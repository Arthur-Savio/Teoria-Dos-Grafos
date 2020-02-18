#include <bits/stdc++.h>

using namespace std;

void print_solution(int dist[], int n)
{
    cout << "Distance from source: " << endl;
    for (int i = 0; i < n; i++)
        cout << i << " dist: " << dist[i] << endl;
}

void bellman_ford(int graph[][3], int V, int E, int src)
{
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {

        for (int j = 0; j < E; j++)
        {
            if (dist[graph[j][0]] + graph[j][2] <
                dist[graph[j][1]])
                dist[graph[j][1]] =
                    dist[graph[j][0]] + graph[j][2];
        }
    }

    for (int i = 0; i < E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
    }

    print_solution(dist, V);
}

int main()
{
    int graph[][3] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    bellman_ford(graph, 5, 8, 0);
    return 0;
}
