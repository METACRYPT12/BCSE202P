#include <iostream>
#include <limits.h>

using namespace std;

#define vertices 50

class Graph
{
private:
    int graph[vertices][vertices];
    int vtx;

public:
    Graph(int vtx)
    {
        this->vtx = vtx;
        for (int i = 0; i < vtx; i++)
        {
            for (int j = 0; j < vtx; j++)
            {
                graph[i][j] = 0;
            }
        }
    }

    void setEdge(bool flag)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y] = w;
        if (flag)
            graph[y][x] = w;
    }

    int minKey(int k[], int mst[])
    {
        int minimum = INT_MAX, min, i;
        for (i = 0; i < vtx; i++)
            if (mst[i] == 0 && k[i] < minimum)
                minimum = k[i], min = i;
        return min;
    }

    void prim()
    {

        int parent[vtx];
        int k[vtx];
        int mst[vtx];
        int i, count, e, v;
        for (i = 0; i < vtx; i++)
        {
            k[i] = INT_MAX;
            mst[i] = 0;
        }

        k[0] = 0;
        parent[0] = -1;
        for (count = 0; count < vtx - 1; count++)
        {

            e = minKey(k, mst);
            mst[e] = 1;
            for (v = 0; v < vtx; v++)
            {
                if (graph[e][v] && mst[v] == 0 && graph[e][v] < k[v])
                {
                    parent[v] = e, k[v] = graph[e][v];
                }
            }
        }

        cout << "\nEdge\tWeight\n";
        for (i = 1; i < vtx; i++)
            printf(" %d - %d  %d \n", parent[i], i, graph[i][parent[i]]);
    }
};
int main()
{
    int v, e;
    bool flag = true;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Keep Graph undirected?(1/0): ";
    cin >> flag;
    cout << "Enter number of edges: ";
    cin >> e;
    Graph *grf = new Graph(v);

    for (int i = 0; i < e; i++)
    {
        cout << "Enter edges in the format u, v, w: ";
        grf->setEdge(flag);
    }
    grf->prim();
    return 0;
}
