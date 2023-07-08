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
#include <string>

using namespace std;

vector<int> node[101];
bool visit[101];

int dfs(int index)
{
    visit[index] = true;
    int sum = 1;
    for (int i = 0; i < node[index].size(); ++i)
    {
        if (!visit[node[index][i]]) sum += dfs(node[index][i]);
    }
    return sum;
}


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    int M; cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int c1, c2; cin >> c1 >> c2;
        node[c1].push_back(c2);
        node[c2].push_back(c1);
    }
    cout << dfs(1) - 1;
}

