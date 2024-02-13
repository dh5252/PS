#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    pair<int, int> loc;
    int dir, lv;
}   node;

int M,N;
bool m[101][101];
int dp[101][101][5];
pair<int, int> s, e;
int s_d, e_d;
queue<node> que;

pair<int, int> mv[5] = {
    {0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}
};

int left(int dir) {
    if (dir == 1) return 4;
    if (dir == 4) return 2;
    if (dir == 2) return 3;
    return 1;
}

int right(int dir) {
    if (dir == 1) return 3;
    if (dir == 4) return 1;
    if (dir == 2) return 4;
    return 2;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>M>>N;
    for(int i = 1 ; i <= M ; ++i) 
        for (int j = 1 ; j <= N ; ++j)  {
            cin>>m[i][j];
            for (int k = 1 ; k <= 4 ; ++k)
                dp[i][j][k] = INT_MAX;
        }

    cin>>s.first>>s.second>>s_d;
    cin>>e.first>>e.second>>e_d;
    
    

    node init;
    init.loc = s;
    init.dir = s_d;
    init.lv = 0;
    que.push(init);
    while (!que.empty()) {
        node cur = que.front();
        que.pop();

        if (cur.lv > dp[cur.loc.first][cur.loc.second][cur.dir])
            continue;
        //cout << "check : " << cur.loc.first << " " << cur.loc.second << " " << cur.dir << " " << cur.lv << "\n";

        if (cur.loc == e && cur.dir == e_d) {
            cout << cur.lv;
            return 0;
        }
        
        for (int i = 1 ; i <= 3 ; ++i) {
            pair<int, int> next = cur.loc;
            next.first += mv[cur.dir].first * i;
            next.second += mv[cur.dir].second * i;
            if (!(next.first >= 1 && next.first <= M && next.second >= 1 && next.second <= N))
                break;
            if (m[next.first][next.second])
                break;
            if (cur.lv + 1 < dp[next.first][next.second][cur.dir]) {
                dp[next.first][next.second][cur.dir] = cur.lv + 1;
                que.push({next, cur.dir, cur.lv + 1});
                
            }
        }
        int l = left(cur.dir);
        int r = right(cur.dir);
        if (cur.lv + 1 < dp[cur.loc.first][cur.loc.second][l]) {
            dp[cur.loc.first][cur.loc.second][l] = cur.lv + 1;
            que.push({cur.loc, l, cur.lv + 1});
        }
        if (cur.lv + 1 < dp[cur.loc.first][cur.loc.second][r]) {
            dp[cur.loc.first][cur.loc.second][r] = cur.lv + 1;
            que.push({cur.loc, r, cur.lv + 1});
        }       
    }
}
