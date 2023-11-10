#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m[101][101];
int N;
int visit[101][101];
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, -1, 1};
int hei;

void dfs(int i, int j)
{
    if (visit[i][j])
        return ;
    visit[i][j] = 1;
    for (int k = 0 ; k < 4 ; ++k)
    {
        int rx = dx[k] + i;
        int ry = dy[k] + j;
        if (rx >= 0 && ry >= 0 && rx < N && ry < N && m[rx][ry] - hei > 0)
            dfs(rx, ry);
    }
}

int cnt(int h)
{
    int c = 0;
    hei = h;
    memset(visit, 0, sizeof(visit));
    for (int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < N ; ++j)
        {
            if (!visit[i][j] && m[i][j] - hei > 0)
            {
                dfs(i, j);
                c++;
            }
        }
    }
    return c;
}





int main()
{
    int max_hei = 0;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
        {
            scanf("%d", &m[i][j]);
            max_hei = max_hei > m[i][j] ? max_hei : m[i][j];
        }
    int max_v = 0;
    for (int i = 0 ; i <= max_hei ; ++i)
    {
        int tmp = cnt(i);
        max_v = max_v > tmp ? max_v : tmp;
    }
    printf("%d", max_v);
}