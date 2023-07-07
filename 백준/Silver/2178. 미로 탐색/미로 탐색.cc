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

char m[101][101];
bool visit[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<pair<int, int>, int> > que;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    
    int N, M; cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)    
            cin >> m[i][j];
        
    
    que.push({ { 0,0 }, 1 });
    while (!que.empty())
    {
        pair<pair<int, int>, int> cur = que.front();
        que.pop();

        if (cur.first.first == N - 1 && cur.first.second == M - 1)
        {
            cout << cur.second;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int cur_x = dx[i] + cur.first.first;
            int cur_y = dy[i] + cur.first.second;
            if (cur_x < 0 || cur_x > N - 1 || cur_y < 0 || cur_y > M - 1) continue;
            if (!visit[cur_x][cur_y] && m[cur_x][cur_y] == '1')
            {
                visit[cur_x][cur_y] = 1;
                que.push({ { cur_x, cur_y }, cur.second + 1 });
            }
        }
    }
   
}

