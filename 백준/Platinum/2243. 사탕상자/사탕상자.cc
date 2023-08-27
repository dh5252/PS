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
#define MAX_SIZE 4000004
using namespace std;

long long tree[MAX_SIZE];

int query(int s, int e, long long find, int node)
{
    if (find < 0)
        return -1;
    if (tree[node] < find)
        return -1;
    if (s == e)
        return s;
    int res = -1;
    res = query(s, (s + e) / 2, find, node * 2);
    if (res == -1)
        res = query((s + e) / 2 + 1, e, find - tree[node * 2], node * 2 + 1);
    return (res);
}

void update(int l, int r, int index, int node, long long diff)
{
    if (index < l || index > r)
        return ;
    tree[node] += diff;
    if (l != r)
    {
        update(l, (l + r) / 2, index, node * 2, diff);
        update((l + r) / 2 + 1, r, index, node * 2 + 1, diff);
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
    {
        long long A,B,C;
        cin >> A >> B;
        if (A == 1)
        {
            int ans = query(1, 1000000, B, 1);
            cout << ans << "\n";
            update(1, 1000000, ans, 1, -1);
        }
        else if (A == 2)
        {
            cin >> C;
            update(1, 1000000, B, 1, C);
        }
    }
    
    return 0;
}