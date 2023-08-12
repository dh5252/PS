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

typedef struct shark
{
    int r,c,s,d,z;
}   shark;

shark sk[10001];
int cur_sk[101][101];
int nearest[101];
int R,C,M;


void next_loc(int cur)
{
    if (sk[cur].d == 1) // up row minus
    {
        int offset = sk[cur].s % (2 * R - 2);
        int dist_f = sk[cur].r - 1;
        int dist_s = R - sk[cur].r;
        if (offset <= dist_f)
        {
            sk[cur].r -= offset;
            return ;
        }
        else if (offset <= dist_f * 2)
        {
            sk[cur].r = offset - dist_f + 1;
            sk[cur].d = 2;
            return ;
        }
        else if (offset <= dist_f * 2 + dist_s)
        {
            sk[cur].r += offset - dist_f * 2;
            sk[cur].d = 2;
            return ;
        }
        else
        {
            sk[cur].r = R - (offset - (dist_f * 2 + dist_s));
            return ;
        }
    }
    if (sk[cur].d == 2)
    {
        int offset = sk[cur].s % (2 * R - 2);
        int dist_f = R - sk[cur].r;
        int dist_s = sk[cur].r - 1;
        if (offset <= dist_f)
        {
            sk[cur].r += offset;
            return ;
        }
        else if (offset <= dist_f * 2)
        {
            sk[cur].r = R - (offset - dist_f);
            sk[cur].d = 1;
            return ;
        }
        else if (offset <= dist_f * 2 + dist_s)
        {
            sk[cur].r -= offset - dist_f * 2;
            sk[cur].d = 1;
            return ;
        }
        else
        {
            sk[cur].r = offset - (dist_f * 2 + dist_s) + 1;
            return ;
        }
    }
    if (sk[cur].d == 3) // right
    {
        int offset = sk[cur].s % (2 * C - 2);
        int dist_f = C - sk[cur].c;
        int dist_s = sk[cur].c - 1;
        if (offset <= dist_f)
        {
            sk[cur].c += offset;
            return ;
        }
        else if (offset <= dist_f * 2)
        {
            sk[cur].c = C - (offset - dist_f);
            sk[cur].d = 4;
            return ;
        }
        else if (offset <= dist_f * 2 + dist_s)
        {
            sk[cur].c -= offset - dist_f * 2;
            sk[cur].d = 4;
            return ;
        }
        else
        {
            sk[cur].c = offset - (dist_f * 2 + dist_s) + 1;
            return ;
        }
    }
    if (sk[cur].d == 4)
    {
        int offset = sk[cur].s % (2 * C - 2);
        int dist_f = sk[cur].c - 1;
        int dist_s = C - sk[cur].c;
        if (offset <= dist_f)
        {
            sk[cur].c -= offset;
            return ;
        }
        else if (offset <= dist_f * 2)
        {
            sk[cur].c = offset - dist_f + 1;
            sk[cur].d = 3;
            return ;
        }
        else if (offset <= dist_f * 2 + dist_s)
        {
            sk[cur].c += offset - dist_f * 2;
            sk[cur].d = 3;
            return ;
        }
        else
        {
            sk[cur].c = C - (offset - (dist_f * 2 + dist_s));
            return ;
        }
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> R >> C >> M;
    
    for (int i = 0 ; i <= C ; ++i)
        nearest[i] = INT_MAX;
    for (int i = 0 ; i < M ; ++i)
    {
        cin >> sk[i].r >> sk[i].c >> sk[i].s >> sk[i].d >> sk[i].z;
        cur_sk[sk[i].r][sk[i].c] = i;
        if (sk[i].c == 1 && nearest[sk[i].c] > sk[i].r) 
            nearest[sk[i].c] = sk[i].r;
    }
    long long sum = 0;
    for (int i = 1 ; i <= C ; ++i)
    {
        //cout << "check : " << sk[2].r << " " << sk[2].c << " " << sk[2].z << " " << sk[2].d << "\n";
        if (nearest[i] != INT_MAX)
        {
            int cur = cur_sk[nearest[i]][i];
            //cout << "check : " << nearest[i] << " " << sk[cur].z  << " " << cur << "\n";
            sum += sk[cur].z;
            sk[cur].z = -1;
        }
        memset(cur_sk, -1, sizeof(cur_sk));
        for (int j = 0 ; j < M ; ++j)
        {
            if (sk[j].z == -1) continue;
            next_loc(j);
            if (cur_sk[sk[j].r][sk[j].c] != -1)
            {
                if (sk[cur_sk[sk[j].r][sk[j].c]].z > sk[j].z)
                    sk[j].z = -1;
                else
                {
                    sk[cur_sk[sk[j].r][sk[j].c]].z = -1;
                    cur_sk[sk[j].r][sk[j].c] = j;
                }
            }
            else
            {
                cur_sk[sk[j].r][sk[j].c] = j;
                if (sk[j].c == i + 1 && nearest[sk[j].c] > sk[j].r)
                    nearest[sk[j].c] = sk[j].r;
            }
        }
    }
    cout << sum;
    return 0;
}