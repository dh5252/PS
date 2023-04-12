#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <set>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

int N;

long long dist[1001][1001];
pair<long long, long long> coordi[1001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> coordi[i].first >> coordi[i].second;
        for (int j = i; j >= 0; --j)
        {
            dist[i][j] = (coordi[i].first - coordi[j].first) * (coordi[i].first - coordi[j].first) + (coordi[i].second - coordi[j].second) * (coordi[i].second - coordi[j].second);
            dist[j][i] = dist[i][j];
        }
    }

    long long min_dist = LLONG_MAX;
    pair<long long, long long> min_pair;
    
    for (int i = 0; i < N; ++i)
    {
        long long max_dist = 0;
        int find = i;
        for (int j = 0; j < N; ++j)
        {
            if (i == j) continue;
            if (max_dist < dist[i][j])
            {
                max_dist = dist[i][j];
                find = j;
            } 
        }
 
        if (min_dist > max_dist)
        {
            min_dist = max_dist;
            min_pair = coordi[i];
        }
    }
    cout << min_pair.first << " " << min_pair.second;
    return 0;
}