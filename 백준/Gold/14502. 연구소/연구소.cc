
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int N,M;
int m[8][8];
int cp_m[8][8];
int visit[8][8];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int max_v;

void dfs(int i, int j)
{
    if (visit[i][j])
        return ;
    visit[i][j] = 1;
    cp_m[i][j] = 2;
    for (int k = 0 ; k < 4 ; ++k)
    {
        int rx = dx[k] + i;
        int ry = dy[k] + j;
        if (rx >= 0 && rx < N && ry >=0 && ry < M && cp_m[rx][ry] == 0)
            dfs(rx, ry);
    }
}

void casework(int i, int j, vector<pair<int, int>> record)
{
    if (record.size() == 3)
    {
        for (int k = 0 ; k < N ; ++k)
            for (int l = 0 ;l<M;++l)
                cp_m[k][l] = m[k][l];
        for (int k=0;k<3;++k)
            cp_m[record[k].first][record[k].second] = 1;
        memset(visit, 0 , sizeof(visit));
        for (int k = 0 ; k < N ; ++k)
            for (int l = 0 ;l<M;++l)
                if (cp_m[k][l] == 2)
                    dfs(k, l);
        
        int cnt = 0;
        for (int k = 0 ; k < N ; ++k)
            for (int l = 0 ;l<M;++l)
                if (cp_m[k][l] == 0)
                    cnt++;
        if (cnt > max_v) max_v = cnt;
        return;
    }
    if (i >= N) return;
    vector<pair<int, int> > cp = record;
    if (m[i][j] == 0)
    {
        cp.push_back({i, j});
        if (j == M - 1)
        {
            casework(i + 1, 0, record);
            casework(i + 1, 0, cp);
        }
        else
        {
            casework(i, j + 1, record);
            casework(i, j + 1, cp);
        }
    }
    else{
        if (j == M - 1)
            casework(i + 1, 0, record);
        else
            casework(i , j + 1, record);
    }
        
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M;
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            cin >> m[i][j];
    vector<pair<int, int> > tmp;
    casework(0 ,0, tmp);
    cout << max_v;
}
