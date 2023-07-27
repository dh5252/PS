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

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;
int m[21][21];
int N;
int max_value;


int max_block(int cur[21][21])
{
    int max_v = 0;
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0; j < N ; ++j)
            max_v = max(max_v, cur[i][j]);
    return max_v;
}

void dfs(int index, int cur[21][21])
{
    if (index == 5)
    {
        max_value = max(max_value, max_block(cur));
        return;
    }

    int limit[21];
    int flag[21][21];

    int up[21][21];
    memset(up, 0, sizeof(up));
    memset(limit, 0, sizeof(limit));
    memset(flag, 0 , sizeof(flag));
    for (int i = 0 ; i < N ; ++i)
    {
        for (int j = 0 ; j < N ; ++j)
        {
            if (!cur[i][j]) continue;
            if (i == 0) up[i][j] = cur[i][j];
            else if (cur[i][j] == up[limit[j]][j] && !flag[limit[j]][j]) 
            {
                flag[limit[j]][j] = 1;
                up[limit[j]][j] <<= 1;
            }
            else if (up[limit[j]][j] == 0) up[limit[j]][j] = cur[i][j];
            else
            {
                if (!cur[i][j]) continue;
                limit[j]++;
                up[limit[j]][j] = cur[i][j];
            }
        }
    }
    dfs(index + 1, up);

    int down[21][21];
    memset(down, 0, sizeof(down));
    memset(flag, 0 , sizeof(flag));
    for (int i = 0 ; i < N ; ++i)
        limit[i] = N - 1;

    for (int i = N - 1 ; i >= 0 ; --i)
    {
        for (int j = 0 ; j < N ; ++j)
        {
            if (!cur[i][j]) continue;
            if (i == N - 1) down[i][j] = cur[i][j];
            else if (cur[i][j] == down[limit[j]][j] && !flag[limit[j]][j])
            {                
                flag[limit[j]][j] = 1;
                down[limit[j]][j] <<= 1;
            }
            else if (down[limit[j]][j] == 0) down[limit[j]][j] = cur[i][j];
            else
            {
                if (!cur[i][j]) continue;
                limit[j]--;
                down[limit[j]][j] = cur[i][j];
            }
        }
    }
    dfs(index + 1, down);

    int left[21][21];
    memset(left, 0, sizeof(left));
    memset(limit, 0, sizeof(limit));
    memset(flag, 0 , sizeof(flag));
    for (int j = 0 ; j < N ; ++j)
    {
        for (int i = 0 ; i < N ; ++i)
        {
            if (!cur[i][j]) continue;
            if (j == 0) left[i][j] = cur[i][j];
            else if (cur[i][j] == left[i][limit[i]] && !flag[i][limit[i]]) 
            {
                flag[i][limit[i]] = 1;
                left[i][limit[i]] <<= 1;
            }
            else if (left[i][limit[i]] == 0) left[i][limit[i]] = cur[i][j];
            else
            {
                if (!cur[i][j]) continue;
                limit[i]++;
                left[i][limit[i]] = cur[i][j];
            }
        }
    }
    dfs(index + 1, left);

    int right[21][21];
    memset(right, 0, sizeof(right));
    memset(flag, 0 , sizeof(flag));
    for (int i = 0 ; i < N ; ++i)
        limit[i] = N - 1;

    for (int j = N - 1 ; j >= 0 ; --j)
    {
        for (int i = 0 ; i < N ; ++i)
        {
            if (!cur[i][j]) continue;
            if (j == N - 1) right[i][j] = cur[i][j];
            else if (cur[i][j] == right[i][limit[i]] && !flag[i][limit[i]]) 
            {
                flag[i][limit[i]] = 1;
                right[i][limit[i]] <<= 1;
            }
            else if (right[i][limit[i]] == 0) right[i][limit[i]] = cur[i][j];
            else
            {
                if (!cur[i][j]) continue;
                limit[i]--;
                right[i][limit[i]] = cur[i][j];
            }
        }
    }
    dfs(index + 1, right);
    
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            cin >> m[i][j];
    dfs(0, m);
    cout << max_value;
}