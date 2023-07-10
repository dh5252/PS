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
#include <string>
#include <unordered_map>

using namespace std;

map<pair<int, int>, long long> hh;
long long cnt[10];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    long long H, W, N; cin >> H >> W >> N;
    for (int i = 0; i < N; ++i)
    {
        int r, c; cin >> r >> c;
        for (int j = r - 2; j <= r; ++j)
            for (int k = c - 2; k <= c; ++k)
                if (j >= 1 && k >= 1 && j + 2 <= H && k + 2 <= W)
                {
                    auto elem = hh.find({ j, k });
                    if (elem != hh.end())
                        elem->second += 1;
                    else
                        hh[{j, k}] = 1;
                    
                }
    }
    long long sum = 0;
    for (auto i : hh)
    {
        cnt[i.second]++;
        ++sum;
    }
    
    long long total = (H - 2) * (W - 2) - sum;
    cout << total << "\n";
    for (int i = 1; i < 10; ++i)
        cout << cnt[i] << "\n";
        
}

