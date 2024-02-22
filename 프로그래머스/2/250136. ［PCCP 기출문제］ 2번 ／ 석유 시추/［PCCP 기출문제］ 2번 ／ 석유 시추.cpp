#include <bits/stdc++.h>

bool v1[501][501];
int v2[501][501];
int N, M;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
bool mass[250000];
int set_number = 1;

using namespace std;

vector<vector<int>> cp;

int dfs(int i, int j)
{
    if (v1[i][j]) return 0;
    
    v1[i][j] = 1;
    int sum = 1;
    for (int k = 0 ; k < 4; ++k)
    {
        int rx = dx[k] + i;
        int ry = dy[k] + j;
        if (rx >= 0 && rx < N && ry >= 0 && ry < M && cp[rx][ry])
            sum += dfs(rx, ry);
    }
    return sum;
}

void fill_blank(int i, int j, int val) {
    if (v2[i][j]) return ;
    v2[i][j] = set_number;
    cp[i][j] = val;
    for (int k = 0 ; k < 4; ++k)
    {
        int rx = dx[k] + i;
        int ry = dy[k] + j;
        if (rx >= 0 && rx < N && ry >= 0 && ry < M && cp[rx][ry])
            fill_blank(rx, ry, val);
    }
}



int solution(vector<vector<int>> land) {
    
    N = land.size();
    M = land[0].size();
    
    cp = land;
    
    for (int i = 0 ; i < N ; ++i)
    {
        for (int j = 0 ; j < M ; ++j)
        {
            if (!v1[i][j] && cp[i][j])
            {
                int val = dfs(i,j);
                fill_blank(i,j,val);
                ++set_number;
            }
        }
    }
    
    int max_val = 0;
    for (int i = 0 ; i < M ; ++i) {
        int val = 0;
        memset(mass, 0, sizeof(mass));
        for (int j = 0 ; j < N ; ++j) {
            if (!mass[v2[j][i]] && cp[j][i])
            {
                mass[v2[j][i]] = 1;
                val += cp[j][i];
            }
        }
        max_val = max(max_val, val);
    }
    
    
    return max_val;
}