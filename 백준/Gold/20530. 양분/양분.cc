#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

pair<int, vector<int> > con[200001];
bool non_cycle[200001];
int meet[200001];
bool visit[200001];


int stk[2000000];
int top = -1;

queue<int> que;

inline void push(int k)
{
    stk[++top] = k;
}

inline int pop()
{
    return stk[top--];
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, Q; cin >> N >> Q;

    for (int i = 0; i < N; ++i)
    {
        int a, b; cin >> a >> b;

        con[a].second.push_back(b);
        con[b].second.push_back(a);
        ++con[a].first;
        ++con[b].first;
    }
    
    for (int i = 1; i <= N; ++i)
        if (con[i].first == 1)
        {
            --con[i].first;
            que.push(i);
        }
    
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        non_cycle[cur] = true;

        for (int i = 0; i < con[cur].second.size(); ++i)
        {
            --con[con[cur].second[i]].first;
            if (con[con[cur].second[i]].first == 1) que.push(con[cur].second[i]);
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        if (!non_cycle[i])
        {
            top = -1;
            push(i);
            while (top != -1)
            {
                int cur = pop();

                if (visit[cur]) continue;
                visit[cur] = 1;

                meet[cur] = i;
                for (int i = 0; i < con[cur].second.size(); ++i)
                    if (non_cycle[con[cur].second[i]])
                        push(con[cur].second[i]);
            }
        }
    }
    
    for (int i = 0; i < Q; ++i)
    {
        int u, v; cin >> u >> v;
        if (meet[u] == meet[v]) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    
}