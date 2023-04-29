#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <limits.h>

using namespace std;


typedef struct table
{
    int x, y, z;
}table;

bool operator<(const table& a, const table& b)
{
    return a.x < b.x;
}

table tb[100001];
int cnt[100001];
int cnt1[100001];
int cnt2[100001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cnt[i] = 1;
        cin >> tb[i].x;
    }
    for (int i = 1; i <= N; ++i)
    {
        cin >> tb[i].y;
        ++cnt1[tb[i].y];
    }
    for (int i = 1; i <= N; ++i)
    {
        cin >> tb[i].z;
        ++cnt2[tb[i].z];
    }
    sort(tb + 1, tb + N + 1);

    int sum = 0;
    queue<int> zero;
    for (int i = 1; i <= N; ++i)
        if (cnt1[i] == 0 || cnt2[i] == 0)
            zero.push(i);
        
    while (!zero.empty())
    {
        int cur = zero.front();
        zero.pop();
        if (cnt[cur] == 0) continue;
        ++sum;
        --cnt[cur];
        if (--cnt1[tb[cur].y] == 0 && cnt[tb[cur].y])
            zero.push(tb[cur].y);
        
        if (--cnt2[tb[cur].z] == 0 && cnt[tb[cur].z])
            zero.push(tb[cur].z);
        
    }
    cout << sum;
}