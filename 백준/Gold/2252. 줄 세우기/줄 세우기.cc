#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;


typedef struct node
{
    vector<int> out;
    int in;
}   node;


node nd[32001];
queue<int> que;
bool visit[32001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

  
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        nd[from].out.push_back(to);
        ++nd[to].in;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (!nd[i].in)
            que.push(i);
    }

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        if (visit[cur])
            break;
        cout << cur << " ";
        visit[cur] = 1;
        for (int i = 0; i < nd[cur].out.size(); ++i)
        {
            --nd[nd[cur].out[i]].in;
            if (nd[nd[cur].out[i]].in == 0)
                que.push(nd[cur].out[i]);
        }
    }
}