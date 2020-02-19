#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_solution(int dist[], int n, int src)
{
    cout << "Distance from: " << src << endl;
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
            if (dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]])
            {
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
            }
        }
    }

    for (int i = 0; i < E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
    }

    print_solution(dist, V, src);
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

    int graph[v][3];

    int count = 0;

    while (file >> src && file >> dest && file >> weight)
    {
        graph[count][0] = src;
        graph[count][1] = dest;
        graph[count][2] = weight;

        count++;
    }

    bellman_ford(graph, v, e, 0);
    return 0;
}
