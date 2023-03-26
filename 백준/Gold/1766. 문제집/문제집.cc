#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node
{
    int in;
    int id;
    vector<int> child;
}   node;

node nd[32001];

bool operator<(const node &a, const node &b)
{
    return a.id > b.id;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);


    int N, M;
    priority_queue<node> pq;

    cin >> N >> M;

    
    
    for (int i = 0 ; i < M ;++i)
    {
        int A, B;

        cin >> A >> B;
        nd[A].child.push_back(B);
        ++nd[B].in;
    }

    for (int i = 1 ; i <= N ;++i)
    {
        nd[i].id = i;
        if (!nd[i].in)
            pq.push(nd[i]);
        
    }
    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();

        cout << cur.id << " ";

        for (int i = 0 ; i < cur.child.size() ; ++i)
        {
            --nd[cur.child[i]].in;
            if (nd[cur.child[i]].in == 0)
                pq.push(nd[cur.child[i]]);
        }
    }


}