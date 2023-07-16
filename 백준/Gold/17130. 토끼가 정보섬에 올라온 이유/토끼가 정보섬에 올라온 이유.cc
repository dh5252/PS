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

using namespace std;

char m[1001][1001];
int dp[1001][1001];
int N, M;

int dx[3] = {-1, 0, 1};
queue<pair<int,int> > que;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> N >> M;
    pair<int, int> start_loc;
    for (int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < M ; ++j)
        {
            cin >> m[i][j];
            if (m[i][j] == 'R') start_loc = make_pair(i,j);
        }
    
    memset(dp, -1, sizeof(dp));
    dp[start_loc.first][start_loc.second] = 0;

    que.push(start_loc);
    while (!que.empty())
    {
        int i = que.front().first;
        int j = que.front().second;
        que.pop();

        if (j == M) continue;

        for (int k = 0 ; k < 3; ++k)
        {
            int rx = dx[k] + i;
            if (rx < 0 || rx >= N || m[rx][j + 1] == '#') continue;

            if (m[rx][j + 1] == 'C')
            {
                if (dp[rx][j + 1] < dp[i][j] + 1) 
                {
                    dp[rx][j + 1] = dp[i][j] + 1;
                    que.push(make_pair(rx, j + 1));
                }
            }
            else
            {
                if (dp[rx][j + 1] < dp[i][j])
                {
                    dp[rx][j + 1] = dp[i][j];
                    que.push(make_pair(rx, j + 1));
                }
            }
        }
    }
    int max_cnt = 0;
    int flag = 0;
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            if (m[i][j] == 'O')
            {
                if (dp[i][j] > -1) flag = 1;
                if (dp[i][j] > max_cnt) max_cnt = dp[i][j];
            }
    if (flag == 0) max_cnt = -1;
    cout << max_cnt;

}