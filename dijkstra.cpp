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

    void dijkstra()
    {

        int k[vtx];
        int mst[vtx];
        int i, count, e, v;
        for (i = 0; i < vtx; i++)
        {
            k[i] = INT_MAX;
            mst[i] = 0;
        }

        k[0] = 0;
        for (count = 0; count < vtx - 1; count++)
        {

            e = minKey(k, mst);
            mst[e] = 1;
            for (v = 0; v < vtx; v++)
            {
                if (graph[e][v] && mst[v] == 0 && k[e] != INT_MAX && k[e] + graph[e][v] < k[v])
                {
                    k[v] = k[e] + graph[e][v];
                }
            }
        }

        cout << "Vertex\tDistance from source";
        for (i = 0; i < vtx; i++)
            printf(" %d\t%d \n", i, k[i]);
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
    grf->dijkstra();
    return 0;
}
