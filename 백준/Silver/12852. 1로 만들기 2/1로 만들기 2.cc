#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node
{
    int value;
    int level;
    vector<int> path;
}   node;

int dp[1000001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    cin >> N;

    queue<node> que;


    que.push({N, 0, vector<int>(0)});
    while (!que.empty())
    {
        node cur = que.front();
        que.pop();
        cur.path.push_back(cur.value);
        if (dp[cur.value])
            continue;
        dp[cur.value] = cur.level;
        if (cur.value == 1)
        {
            cout << cur.level << "\n";
            for (int i = 0 ; i < cur.path.size() ; ++i)
                cout << cur.path[i] << " ";
            break;
        }
        if (cur.value % 3 == 0)
            que.push({cur.value / 3, cur.level + 1, cur.path});
        if (cur.value % 2 == 0)
            que.push({cur.value >> 1, cur.level + 1, cur.path});
        que.push({cur.value - 1, cur.level + 1, cur.path});
    }
}