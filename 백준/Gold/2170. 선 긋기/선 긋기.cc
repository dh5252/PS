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

typedef struct node
{
    int x,y;
}node;

bool operator<(const node &a, const node &b)
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

node s[1000001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0 ; i < N ; ++i)
        cin >> s[i].x >> s[i].y;
    sort(s, s + N);
    int sum = 0;
    int l = s[0].x, r = s[0].y;
    for (int i = 1 ; i < N ; ++i)
    {
        if (r < s[i].x)
        {
            sum += r - l;
            l = s[i].x;
            r = s[i].y;
        }
        else if (r < s[i].y)
            r = s[i].y;
    }
    sum += r - l;
    cout << sum;
}