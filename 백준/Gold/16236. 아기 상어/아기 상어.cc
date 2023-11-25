#include <bits/stdc++.h>
using namespace std;

typedef struct fish
{
    int i,j,size,time,cnt;
} fish;

bool operator<(const fish &a, const fish &b)
{
    if (a.i == b.i)
        return a.j < b.j;
    return a.i < b.i;
}


int N;
int m[20][20];
fish shark;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1, 1,0};
bool v[20][20];

void bfs()
{
    queue<fish> que;    
    que.push(shark);
    memset(v, 0, sizeof(v));
    int min_time = INT_MAX;
    vector<fish> check;
    while (!que.empty())
    {
        fish cur = que.front();
        que.pop();

        if (v[cur.i][cur.j]) continue;
        v[cur.i][cur.j] = 1;

        if (cur.time > min_time) continue;

        if (m[cur.i][cur.j] != 0 && m[cur.i][cur.j] < cur.size)
        {
            check.push_back(cur);
            min_time = cur.time;
            continue;
        }
        for (int i=0;i<4;++i)
        {
            int rx = cur.i + dx[i];
            int ry = cur.j + dy[i];
            if (rx >= 0 && rx < N && ry >= 0 && ry < N && cur.size >= m[rx][ry])
                que.push({rx,ry,cur.size, cur.time+1,cur.cnt});
        }
    }
    fish min_s = {INT_MAX, INT_MAX};
    for (int i = 0 ; i < check.size() ; ++i)
        min_s = min(min_s, check[i]);
    
    if (min_s.i == INT_MAX) return;
    m[min_s.i][min_s.j] = 0;
    shark = min_s;
    if (++shark.cnt == shark.size)
    {
        shark.cnt = 0;
        ++shark.size;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < N ;++j)
        {
            cin >> m[i][j];
            if (m[i][j] == 9)
            {
                m[i][j] = 0;
                shark.i = i;
                shark.j = j;
                shark.size = 2;
                shark.time = 0;
                shark.cnt = 0;
            }
        }
    int before = -1;

    while (before != shark.time)
    {
        before = shark.time;
        bfs();
    }
    cout << shark.time;
    return 0;
}
