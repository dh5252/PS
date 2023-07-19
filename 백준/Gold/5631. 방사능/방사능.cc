#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <queue>

#define ABS(x) ( ((x)<0)?-(x):(x) ) 

using namespace std;

pair<long long, long long> h[200001];
long long dist_a[200001];
long long dist_b[200001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    for (int t = 1; t <= 4; ++t)
    {
        int N; cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; ++i)
            cin >> h[i].first >> h[i].second;
        long long ax, ay, bx, by, q;
        cin >> ax >> ay >> bx >> by >> q;
        for (int i = 0; i < N; ++i)
        {
            dist_a[i] = (h[i].first - ax) * (h[i].first - ax) + (h[i].second - ay) * (h[i].second - ay);
            dist_b[i] = (h[i].first - bx) * (h[i].first - bx) + (h[i].second - by) * (h[i].second - by);
        }
        sort(dist_a, dist_a + N);
        sort(dist_b, dist_b + N);
        cout << "Case " << t << ":\n";
        for (int i = 0; i < q; ++i)
        {
            long long R1, R2; cin >> R1 >> R2;
            R1 = R1 * R1;
            R2 = R2 * R2;
            
            int k1 = upper_bound(dist_a, dist_a + N, R1) - dist_a;
            int k2 = upper_bound(dist_b, dist_b + N, R2) - dist_b;

            cout << (N - k1 - k2 >= 0 ? N - k1 - k2 : 0) << "\n";
        }
    }
}