#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

typedef struct node
{
    vector<pair<int, int> > coordi;
}   node;

node nd[26];
bool key[26];
char map[100][100];
bool visit[100][100];
vector<pair<int, int> > start;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int h, w;
int cnt;

void dfs(int cur_i, int cur_j)
{
    if (map[cur_i][cur_j] >= 'A' && map[cur_i][cur_j] <= 'Z')
    {
        if (!key[map[cur_i][cur_j] - 'A'])
        {
            nd[map[cur_i][cur_j] - 'A'].coordi.push_back({ cur_i, cur_j });
            return;
        }
        else
            map[cur_i][cur_j] = '.';
    }
    if (map[cur_i][cur_j] >= 'a' && map[cur_i][cur_j] <= 'z')
    {
        key[map[cur_i][cur_j] - 'a'] = 1;
        for (int i = 0; i < nd[map[cur_i][cur_j] - 'a'].coordi.size(); ++i)
        {
            map[nd[map[cur_i][cur_j] - 'a'].coordi[i].first][nd[map[cur_i][cur_j] - 'a'].coordi[i].second] = '.';
            start.push_back(nd[map[cur_i][cur_j] - 'a'].coordi[i]);
        }
        nd[map[cur_i][cur_j] - 'a'].coordi.clear();
    }

    if (visit[cur_i][cur_j])
        return;

    visit[cur_i][cur_j] = 1;

    if (map[cur_i][cur_j] == '$') ++cnt;

    for (int i = 0; i < 4; ++i)
    {
        int x = cur_i + dx[i];
        int y = cur_j + dy[i];
        if (x >= 0 && x < h && y >= 0 && y < w && map[x][y] != '*' && !visit[x][y])
            dfs(x, y);
        
    }
}

bool is_start(int i, int j)
{
    return (map[i][j] != '*');
}


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);


    int T;

    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> h >> w;
        memset(key, 0, sizeof(key));
        memset(nd, 0, sizeof(nd));
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) 
                cin >> map[i][j];
             
        string k;
        cin >> k;
        for (int i = 0; i < k.length(); ++i)
        {
            if (k[i] == '0') break;
            for (int j = 0; j < nd[k[i] - 'a'].coordi.size(); ++j)
                map[nd[k[i] - 'a'].coordi[j].first][nd[k[i] - 'a'].coordi[j].second] = '.';
            nd[k[i] - 'a'].coordi.clear();
            key[k[i] - 'a'] = 1;
        }

        start.clear();

        for (int i = 0; i < h; ++i)
        {
            if (is_start(i, 0)) start.push_back({i, 0});
            if (is_start(i, w - 1)) start.push_back({i, w - 1});
        }
        for (int i = 0; i < w; ++i)
        {
            if (is_start(0, i)) start.push_back({0, i});
            if (is_start(h - 1, i)) start.push_back({h - 1, i});
        }
        cnt = 0;
        for (int i = 0; i < start.size(); ++i)
            dfs(start[i].first, start[i].second);
        
        cout << cnt << "\n";
    }
}