#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <limits.h>
#include <list>
#include <stack>

#define ABS(x) ( ((x)<0)?-(x):(x) ) 

using namespace std;

int N, M, L;
string str;
char m[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cycle;
pair<pair<int, int>, int> save; 

void dfs(long long index, int i, int j, bool visit[101][101])
{
    if (cycle) return;
    visit[i][j]= 1;
    if (index % L == L - 1)
    {
        if (index / L + 1 > save.second)
        {
            save.first = make_pair(i, j);
            save.second = index / L + 1;
        }
    }
    for (int k = 0 ; k < 4 ; ++k)
    {
        int rx = dx[k] + i;
        int ry = dy[k] + j;
        if (rx <= 0 || ry <= 0 || rx > N || ry > M) continue;
        if (m[rx][ry] != str[(index + 1) % L]) continue;
        if (visit[rx][ry])
        {
            cycle = 1;
            return;
        }
        dfs(index + 1, rx, ry, visit);
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> N >> M >> L;
    cin >> str;
    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j <= M ; ++j)
            cin >> m[i][j];
    bool visit[101][101] = {};
    dfs(0, 1, 1, visit);
    if (cycle || save.first.first == 0 || save.first.second == 0)
        cout << -1;
    else
        cout << save.second << "\n" << save.first.first << " " << save.first.second;
}