#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <limits.h>

using namespace std;

typedef struct node
{
    vector<int> con;
    int degree;
}   node;

node nd[100001];
bool visit[100001];

int dfs(int cur)
{
    visit[cur] = true;
    int sum = 1;
    for (int i = 0; i < nd[cur].con.size(); ++i)
        if (!visit[nd[cur].con[i]])
            sum += dfs(nd[cur].con[i]);
    nd[cur].degree = sum;
    return sum;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, R, Q;
    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        nd[u].con.push_back(v);
        nd[v].con.push_back(u);
    }
    dfs(R);
    for (int i = 0; i < Q; ++i)
    {
        int q;
        cin >> q;
        cout << nd[q].degree << "\n";
    }
}

