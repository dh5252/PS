#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef struct edge
{
    int wei;
    int c1;
    int c2;
}   edge;

bool operator<(const edge &a, const edge &b)
{
    return a.wei > b.wei;
}

typedef struct node
{
    vector<edge> connect;
    int visit;
}   node;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    priority_queue<edge> min_heap;

    int V, E; 
    cin >> V >> E;

    node vertice[10001];
    edge eg[100000];
    int edge_num = 0;
    for (int i = 0 ; i < E ; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        eg[edge_num].wei = C;
        eg[edge_num].c1 = A;
        eg[edge_num].c2 = B;
        vertice[A].connect.push_back(eg[edge_num]);
        vertice[B].connect.push_back(eg[edge_num]);
    }

    int cnt = 0, sum = 0;
    vertice[1].visit = 1;
    ++cnt;
    for (int i = 0 ; i < vertice[1].connect.size() ; ++i)
        min_heap.push(vertice[1].connect[i]);
    
    while (cnt < V)
    {
        edge pop = min_heap.top();
        min_heap.pop();
        int next = -1;
        if (!vertice[pop.c1].visit)
            next = pop.c1;
        if (!vertice[pop.c2].visit)
            next = pop.c2;
        if (next == -1)
            continue;
        vertice[next].visit = 1;
        sum += pop.wei;
        ++cnt;
        for (int i = 0 ; i < vertice[next].connect.size() ; ++i)
            min_heap.push(vertice[next].connect[i]);
    }
    cout << sum << "\n";
    
}