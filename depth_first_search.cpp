#include <iostream>
#define MAX 10

using namespace std;

class Graph
{
private:
    int adj[MAX][MAX];
    int n;
    int *visited;
    void set_adj(int, int);

public:
    Graph(int);
    ~Graph();
    void read();
    void dfs(int);
    void print_adjMat();
    void print_dfs();
};

Graph::Graph(int n)
{
    this->n = n;
    visited = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
}

Graph::~Graph()
{
}

void Graph::set_adj(int x, int y)
{
    adj[x][y] = 1;
}

void Graph::read()
{
    int x, y;
    cout << "Enter u and v( u -> v ): ";
    cin >> x >> y;
    if (x != y)
        set_adj(x, y);
    else
        cout << "Cannot make a loop" << endl;
}

void Graph::dfs(int root)
{
    cout << root << " -> ";
    visited[root] = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && adj[root][i] == 1)
            dfs(i);
    }

    return;
}

void Graph::print_adjMat()
{
    cout << "The Adjacency Matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::print_dfs()
{
    cout << "Depth First Search: \n\n";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    int v, e;
    cout << "Enter number of Vertices: ";
    cin >> v;
    cout << "Enter number of Edges: ";
    cin >> e;
    Graph grf(v);
    for (int i = 0; i < e; i++)
    {
        grf.read();
    }
    grf.print_adjMat();
    grf.print_dfs();
}