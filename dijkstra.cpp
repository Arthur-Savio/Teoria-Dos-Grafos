#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define V 9

int min_distance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

int print_solution(int dist[], int src)
{
    cout << "Distance from: " << src << endl;
    for (int i = 0; i < V; i++)
        cout << i << " dist: " << dist[i] << endl;
}

void dijkstra(int graph[][3], int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = min_distance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    print_solution(dist, src);
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
        cout << "Incorrect arguments." << endl;
        return false;
    }
    else if (!file_exist(argv[1]))
    {
        cout << "File " << argv[1] << " not found." << endl;
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

    dijkstra(graph, 0);

    return 0;
}
