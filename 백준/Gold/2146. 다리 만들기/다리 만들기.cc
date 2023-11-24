#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    bool val;
    int id;
}   node;


int N;
node m[101][101];
bool v[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void dfs(int i, int j, int id)
{
    if (v[i][j]) return;

    v[i][j] = 1;
    m[i][j].id = id;
    for(int k = 0 ; k < 4 ; ++k)
    {
        int rx = dx[k] + i;
        int ry = dy[k] + j;

        if (rx >= 0 &&ry>=0&&rx<N&&ry<N&&m[rx][ry].val)
            dfs(rx,ry,id);
    }
}

int bfs(int i, int j, int id)
{
    queue<pair<pair<int, int>, int>> que;
    que.push({{i,j}, 0});
    int min_val = INT_MAX;

    memset(v, 0 ,sizeof(v));
    while (!que.empty())
    {
        pair<pair<int, int>, int> cur = que.front();
        que.pop();

        if (v[cur.first.first][cur.first.second]) continue;
        v[cur.first.first][cur.first.second] = 1;
        
        if (m[cur.first.first][cur.first.second].id != 0 && m[cur.first.first][cur.first.second].id != m[i][j].id)
        {
            min_val = min(min_val, cur.second);
            continue;
        }

        for (int k = 0 ; k<4;++k)
        {
            int rx = dx[k] + cur.first.first;
            int ry = dy[k] + cur.first.second;

            if (rx >= 0 &&ry>=0&&rx<N&&ry<N&& m[rx][ry].id != id)
                que.push({{rx, ry}, cur.second + 1});
        }
    }
    return min_val;
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cin >> m[i][j].val;
    
    int cnt = 1;
    for (int i = 0 ; i < N ; ++i)
        for(int j =0;j<N;++j)
        {
            if (m[i][j].val == 1 && !v[i][j])
                dfs(i,j,cnt++);
        }

    int min_val = INT_MAX;
    for (int i = 0 ; i < N ; ++i)
        for(int j =0;j<N;++j)
            if (m[i][j].val == 1)
                min_val = min(min_val, bfs(i, j, m[i][j].id));

    cout << min_val - 1;
    
    return 0;
}
