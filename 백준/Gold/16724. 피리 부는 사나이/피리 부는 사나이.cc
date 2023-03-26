#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

char dir[1000][1000];
bool visit[1000][1000];
int id[1000][1000];
int cycle_cnt;


void travel(int set_id, int x, int y)
{
    if (id[x][y] == set_id)
    {
        ++cycle_cnt;
        return;
    }
    if (visit[x][y])
        return;
    visit[x][y] = 1;
    id[x][y] = set_id;
    if (dir[x][y] == 'U')
        travel(set_id, x - 1, y);
    if (dir[x][y] == 'D')
        travel(set_id, x + 1, y);
    if (dir[x][y] == 'L')
        travel(set_id, x, y - 1);
    if (dir[x][y] == 'R')
        travel(set_id, x, y + 1);
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> dir[i][j];

    int cur_id = 1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!visit[i][j])
            {
                if (dir[i][j] == 'U')
                    travel(cur_id++, i - 1, j);
                if (dir[i][j] == 'D')
                    travel(cur_id++, i + 1, j);
                if (dir[i][j] == 'L')
                    travel(cur_id++, i, j - 1);
                if (dir[i][j] == 'R')
                    travel(cur_id++, i, j + 1);
            }
    cout << cycle_cnt;
}