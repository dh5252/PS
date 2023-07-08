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

char m[26][26];
bool visit[26][26];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int N;

int dfs(int i, int j)
{
    visit[i][j] = true;
    int sum = 1;
    for (int k = 0; k < 4; ++k)
    {
        int x = dx[k] + i;
        int y = dy[k] + j;
        if (x >= 0 && y >= 0 && x < N && y < N && m[x][y] == '1' && !visit[x][y])
            sum += dfs(x, y);
    }
    return sum;
}



int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> m[i][j];

    vector<int> vec;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (m[i][j] == '1' && !visit[i][j])
                vec.push_back(dfs(i, j));
    cout << vec.size() << "\n";
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << "\n";
}

