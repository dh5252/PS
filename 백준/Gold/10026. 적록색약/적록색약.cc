
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
bool v[101][101];
int N;
char m[101][101];

void dfs1(int i, int j, char c) {
    
    if (v[i][j])
        return;
    v[i][j] = 1;
    
    for (int k = 0 ; k < 4 ; ++k) {
        
        int rx = dx[k] + i;
        int ry = dy[k] + j;
        if (rx >= 0 && ry >= 0 && rx < N && ry < N && m[rx][ry] == c)
            dfs1(rx, ry, c);
    }
}

void dfs2(int i, int j, char c) {
    if (v[i][j])
        return;
    v[i][j] = 1;
    
    for (int k = 0 ; k < 4 ; ++k) {
        
        int rx = dx[k] + i;
        int ry = dy[k] + j;
        if (rx >= 0 && ry >= 0 && rx < N && ry < N) {
            if ((c == 'R' || c == 'G') && (m[rx][ry] == 'R' || m[rx][ry] == 'G'))
                dfs2(rx, ry, c);
            else if (c == m[rx][ry])
                dfs2(rx, ry, c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin>>N;
    for(int i = 0; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
            cin>>m[i][j];
    
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
            if (!v[i][j]) {
                dfs1(i, j, m[i][j]);
                ans1++;
            }
    memset(v, 0, sizeof(v));
    for(int i = 0; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
            if (!v[i][j]) {
                dfs2(i, j, m[i][j]);
                ans2++;
            }
    
    cout << ans1 << " " << ans2;
    return 0;
}
