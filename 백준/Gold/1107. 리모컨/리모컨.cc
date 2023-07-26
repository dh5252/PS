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
#define MAX_SIZE 100001

using namespace std;

bool broken[10];
queue<pair<int, int> > que;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    int M; cin >> M;
    for (int i = 0 ; i < M ; ++i)
    {
        int in; cin >> in;
        broken[in] = true; 
    }
    int d = ABS(100 - N);
    
    que.push({0, 0});
    pair<int, int> min_value = {INT_MAX, 0};
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        if (cur.second == 7) break;
        for (int i = 0 ; i < 10 ; ++i)
        {
            if (broken[i]) continue;
            int next = cur.first * 10 + i;
            if (ABS(N - next) < min_value.first) min_value = {ABS(N - next), cur.second + 1};
            que.push({next, cur.second + 1});
        }
    }
    cout << min(min_value.first + min_value.second , d);
}