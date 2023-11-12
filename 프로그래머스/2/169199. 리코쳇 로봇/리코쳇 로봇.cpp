#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> cur, des;
bool v[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1,-1,0,0};

int solution(vector<string> board) {
    
    N = board.size();
    M = board[0].length();
    
    for (int i = 0 ; i < N ; ++i)
    {
        for (int j = 0 ; j < M ; ++j)
        {
            if (board[i][j] == 'R')
                cur = {i, j};
            else if (board[i][j] == 'G')
                des = {i, j};
        }
    }
    
    queue<pair<pair<int, int>, int>> que;
    que.push({cur, 0});
    while (!que.empty())
    {
        pair<pair<int, int>, int> c = que.front();
        que.pop();
        
        if (v[c.first.first][c.first.second]) continue;
        cout << "check : " << c.first.first << " " << c.first.second << " " << c.second << "\n";
        v[c.first.first][c.first.second] = true;
        if (c.first == des)
            return c.second;
        for (int i = 0 ;i<4;++i)
        {
            int rx = c.first.first;
            int ry = c.first.second;
            while (rx + dx[i] >= 0 && rx + dx[i] < N && ry + dy[i] >= 0 && ry + dy[i] < M && board[rx + dx[i]][ry + dy[i]] != 'D')
            {
                rx += dx[i];
                ry += dy[i];
            }
            
            if (!(rx == c.first.first && ry == c.first.second))
                que.push({{rx, ry}, c.second + 1});
        }
    }
    return -1;
    
}