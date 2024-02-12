#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    pair<int, int> r_loc;
    pair<int, int> b_loc;
    int cnt;
    bool r_v[4][4];
    bool b_v[4][4];
}   node;

queue<node> que;
int N, M;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int solution(vector<vector<int>> maze) {
    
    pair<int,int> r_s, b_s, r_e, b_e;
    
    N = maze.size();
    M = maze[0].size();
    
    for (int i = 0 ; i < maze.size() ; ++i) {
        for (int j = 0 ; j < maze[i].size() ; ++j) {
            if (maze[i][j] == 1) r_s = make_pair(i, j);
            else if (maze[i][j] == 2) b_s = make_pair(i, j);
            else if (maze[i][j] == 3) r_e = make_pair(i, j);
            else if (maze[i][j] == 4) b_e = make_pair(i, j);
        }
    }
    node init;
    init.r_loc = r_s;
    init.b_loc = b_s;
    init.cnt = 0;
    memset(init.r_v, 0, sizeof(init.r_v));
    memset(init.b_v, 0, sizeof(init.b_v));
    que.push(init);
    while (!que.empty()) {
        node cur = que.front();
        que.pop();
                
        if (cur.r_loc == r_e && cur.b_loc == b_e) {
            return cur.cnt;
        }
        vector<pair<int, int> > r_move;
        vector<pair<int, int> > b_move;
        
        cur.r_v[cur.r_loc.first][cur.r_loc.second] = 1;
        cur.b_v[cur.b_loc.first][cur.b_loc.second] = 1;
        
        if (cur.r_loc != r_e) {
            for (int i = 0 ; i < 4 ; ++i) {
                int rx = dx[i] + cur.r_loc.first;
                int ry = dy[i] + cur.r_loc.second;
                if (rx >= 0 && ry >= 0 && rx < N && ry < M && maze[rx][ry] != 5 && !cur.r_v[rx][ry]) {
                    r_move.push_back({rx, ry});
                }
            }
        }
        if (cur.b_loc != b_e) {
            for (int i = 0 ; i < 4 ; ++i) {
                int rx = dx[i] + cur.b_loc.first;
                int ry = dy[i] + cur.b_loc.second;
                if (rx >= 0 && ry >= 0 && rx < N && ry < M && maze[rx][ry] != 5 && !cur.b_v[rx][ry]) {
                    b_move.push_back({rx, ry});
                }
            }
            
        }
        if (cur.r_loc == r_e) {
            for (int i = 0 ; i < b_move.size() ; ++i) {
                if (b_move[i] == r_e) continue;
                node next = cur;
                next.b_loc = b_move[i];
                next.cnt = cur.cnt + 1;
                que.push(next);
            }
        }
        else if (cur.b_loc == b_e) {
            for (int i = 0 ; i < r_move.size() ; ++i) {
                if (r_move[i] == b_e) continue;
                node next = cur;
                next.r_loc = r_move[i];
                next.cnt = cur.cnt + 1;
                que.push(next);
            }
        }
        else {
            for (int i = 0 ; i < r_move.size() ; ++i) {
                for (int j = 0 ; j < b_move.size() ; ++j) {
                    if (r_move[i] == b_move[j])
                        continue;
                    if (r_move[i] == cur.b_loc && b_move[j] == cur.r_loc)
                        continue;
                    node next = cur;
                    next.r_loc = r_move[i];
                    next.b_loc = b_move[j];
                    next.cnt = cur.cnt + 1;
                    que.push(next);
                }
            }
        }
    }
    
    return 0;
}