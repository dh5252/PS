#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node
{
    int in;
    vector<int> child;
}   node;


node nd[1001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M;

    cin >> N >> M;
    for (int i = 0 ; i < M ; ++i)
    {
        int q;
        cin >> q;
        int f;
        cin >> f;
        for (int j = 0 ; j < q - 1 ; ++j)
        {
            int s;
            cin >> s;
            nd[f].child.push_back(s);
            ++nd[s].in;
            f = s;
        }
    }

    queue<int> que;
    vector<int> order;
    int visit = 0;
    for (int i = 1 ; i <= N ; ++i)
    {
        if (!nd[i].in)
            que.push(i);
    }
    while (!que.empty())
    {
        int cur = que.front();
        order.push_back(cur);
        ++visit;
        que.pop();
        for (int i = 0 ; i < nd[cur].child.size() ; ++i)
        {
            if (--nd[nd[cur].child[i]].in == 0)
                que.push(nd[cur].child[i]);
        }
    }
    if (visit < N)
        cout << 0;
    else
    {
        for (int i = 0 ; i < order.size() ; ++i)
            cout << order[i] << "\n";
    }
}