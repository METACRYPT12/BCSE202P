// sort by weight
// pick smallest, include in no cycle is formed
// repeat 2

#include <iostream>
#include <vector>
// #include "mergesort.h"
#include <algorithm>

using namespace std;

class Edge
{
public:
    int u, v, weight;
    Edge(int, int, int);
    ~Edge();
};

Edge::Edge(int u, int v, int weight)
{
    this->u = u;
    this->v = v;
    this->weight = weight;
}

Edge::~Edge() {}

class disjoint_set
{
private:
    int *parent;
    int *rank;

public:
    disjoint_set(int);
    int find(int);
    void make_union(int, int);
    void swap(int &, int &);
    ~disjoint_set();
};

void disjoint_set::swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
    return;
}

disjoint_set::disjoint_set(int n)
{
    parent = new int[n];
    rank = new int[n];

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

disjoint_set::~disjoint_set()
{
    delete parent;
    delete rank;
}

int disjoint_set::find(int node)
{
    if (node == parent[node])
        return node;

    // path compression
    return (parent[node] = find(parent[node]));
}

void disjoint_set::make_union(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u != v)
    {
        if (rank[u] < rank[v])
            swap(u, v);
        // attach lower tree
        parent[v] = u;
        // inc rank of u
        if (rank[u] == rank[v])
            rank[u]++;
    }
}

class Graph
{
private:
    vector<Edge> edge;
    int v, e;

public:
    Graph();
    Graph(int, int);
    void addEdge(int, int, int);
    void MST_build();
    ~Graph();
};

Graph::Graph()
{
    this->v = 0;
    this->e = 0;
}

Graph::Graph(int v, int e)
{
    this->v = v;
    this->e = e;
}

Graph::~Graph()
{
    edge.~vector<Edge>();
}

void Graph::addEdge(int u, int v, int weight)
{
    edge.push_back(Edge(u, v, weight));
}

bool compare_fn(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void Graph::MST_build()
{
    int e_counter = 0;
    int i = 0;
    int sum = 0;
    disjoint_set set(v);

    // sort(edge, edge.end() - edge.begin());
    sort(edge.begin(), edge.end(), compare_fn);

    while (e_counter < v - 1)
    {
        Edge tmp = edge[i++];
        int U = set.find(tmp.u);
        int V = set.find(tmp.v);
        if (U != V)
        {
            cout << tmp.u << "-----" << tmp.v << endl;
            sum = sum + tmp.weight;

            set.make_union(U, V);
            e_counter++;
        }
    }
    cout << "MST weight: " << sum;
}

int main()
{
    int V, E;
    int u, v, weight;
    char opt;
start:
    cout << "Disjoint Set Implementation Kruskal`s Minimum Spanning Tree" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of Edges: ";
    cin >> E;
    Graph grf(V, E);
    cout << "Enter " << E << " Edges in the format \"u v weight\"" << endl;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> weight;
        grf.addEdge(u, v, weight);
    }

    cout << endl;
    grf.MST_build();
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Restart?(y/n) " << endl;
    cin >> opt;

    /*
    if (opt == 'y')
    {
        cout << "\033[2J\033[1;1H";
        grf.~Graph();
        goto start;
    }
    */

    return 0;
}