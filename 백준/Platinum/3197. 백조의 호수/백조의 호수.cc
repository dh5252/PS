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
#include <unordered_set>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

pair<int, int> parent[1501][1501];
char m[1501][1501];
int id[1501][1501];
int uid = 1;
int key_id[2];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int R, C;
queue<pair<pair<int, int>, int> > que;


void dfs(int i, int j, pair<int, int> root)
{
    if (parent[i][j] != make_pair(i, j))
        return ;
    parent[i][j] = root;
    for (int k = 0 ; k < 4 ; ++k)
    {
        int rx = dx[k] + i;
        int ry = dy[k] + j;
        if (rx >= 0 && rx < R && ry >= 0 && ry < C && m[rx][ry] != 'X')
            dfs(rx, ry, root);
    }
}

bool is_inner(int i, int j)
{
    for (int k = 0 ; k < 4 ; ++k)
    {
        int rx = dx[k] + i;
        int ry = dy[k] + j;
        if (rx >= 0 && rx < R && ry >= 0 && ry < C && m[rx][ry] == 'X')
            return 0;
    }
    return 1;
}

pair<int, int> find(pair<int, int> cur)
{
    if (cur == parent[cur.first][cur.second])
        return cur;
    
    return parent[cur.first][cur.second] = find(parent[cur.first][cur.second]);
}

void union_set(pair<int, int> r1, pair<int, int> r2)
{
    parent[r2.first][r2.second] = r1;
    if (id[r2.first][r2.second] == key_id[0]) key_id[0] = id[r1.first][r1.second];
    if (id[r2.first][r2.second] == key_id[1]) key_id[1] = id[r1.first][r1.second];
}

bool is_ans(pair<int,int> &r1, pair<int,int> &r2)
{
    if (key_id[0] == id[r1.first][r1.second] && key_id[1] == id[r2.first][r2.second])
        return 1;
    if (key_id[1] == id[r1.first][r1.second] && key_id[0] == id[r2.first][r2.second])
        return 1;
    return 0;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> R >> C;
    for (int i = 0 ; i < R ; ++i)
        for (int j = 0 ; j < C ; ++j)
        {
            cin >> m[i][j];
            parent[i][j] = {i, j};
        }
    for (int i = 0 ; i < R ; ++i)
        for (int j = 0 ; j < C ; ++j)
        {
            if ((m[i][j] == '.' || m[i][j] == 'L') && (parent[i][j] == make_pair(i, j)))
            {
                id[i][j] = uid++;
                dfs(i, j, {i,j});
            }
            if ((m[i][j] == '.' || m[i][j] == 'L') && !is_inner(i, j))
                que.push({{i, j}, 0});
            if (m[i][j] == 'L')
            {
                pair<int, int> key_root = find({i, j});
                if (key_id[0] == 0)
                    key_id[0] = id[key_root.first][key_root.second];
                else
                    key_id[1] = id[key_root.first][key_root.second];
            }
        }
    
    while (!que.empty())
    {
        pair<pair<int, int>, int> cur = que.front();
        //cout << cur.first.first << " " << cur.first.second << " " << cur.second << "\n"; 
        que.pop();
        for (int k = 0 ; k < 4 ; ++k)
        {
            int rx = dx[k] + cur.first.first;
            int ry = dy[k] + cur.first.second;
            if (rx >= 0 && rx < R && ry >= 0 && ry < C)
            {
                if (m[rx][ry] == 'X')
                {
                    m[rx][ry] = '.';
                    if (!is_inner(rx,ry))
                        que.push({{rx, ry}, cur.second + 1});
                    parent[rx][ry] = cur.first;
                    for (int kk = 0 ; kk < 4 ; ++kk)
                    {
                        int rrx = dx[kk] + rx;
                        int rry = dy[kk] + ry;
                        if (rrx >= 0 && rrx < R && rry >= 0 && rry < C && m[rrx][rry] != 'X')
                        {
                            pair<int, int> r1 = find({rrx, rry});
                            pair<int, int> r2 = find({rx, ry});
                            if (r1 != r2)
                            {
                                //cout << r1.first << " " << r1.second << " " << r2.first << " " << r2.second << "check\n"; 
                                if (is_ans(r1, r2))
                                {
                                    cout << cur.second + 1;
                                    return 0;
                                }
                                union_set(r1, r2);
                            }
                        }
                        
                    }
                    
                }
                else
                {
                    pair<int, int> r1 = find({cur.first.first, cur.first.second});
                    pair<int, int> r2 = find({rx, ry});
                    if (r1 != r2)
                    {
                        if (is_ans(r1, r2))
                        {
                            cout << cur.second;
                            return 0;
                        }
                        union_set(r1, r2);
                    }
                    else if (is_ans(r1, r2))
                    {
                        cout << cur.second;
                        return 0;
                    }
                }
            }
                
        }  
    }
    return 0;
}