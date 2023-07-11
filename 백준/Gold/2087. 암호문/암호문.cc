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

using namespace std;

int a[41];
int n; 
vector<pair<int, long long> > a1,a2;

vector<int> ans;

bool comp(const pair<int, long long> &a, const pair<int, long long> &b)
{
    return a.first < b.first;
}

void dfs(int level, long long mode, int sum, int limit)
{
    if (level == limit) 
    {
        if (limit == n / 2) a1.push_back(make_pair(sum ,mode));
        else a2.push_back(make_pair(sum,mode));
        return;
    }
    dfs(level + 1, (mode << 1) | 1, sum + a[level], limit);
    dfs(level + 1, (mode << 1), sum, limit);
}

void convert_binary(long long demi)
{
    if (demi > 0)
    {
        convert_binary(demi / 2);
        ans.push_back(demi % 2);
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0 ; i < n ; ++i) cin >> a[i];

    int K; cin >> K;

    dfs(0, 0, 0, n / 2);
    dfs(n / 2, 0, 0, n);
    
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    for (int i = 0 ; i < a1.size() ; ++i)
    {
        auto k = lower_bound(a2.begin(), a2.end(), make_pair(K - a1[i].first, 0), comp) - a2.begin();
        
        if (k == a2.size()) continue;
        else if (a2[k].first == K - a1[i].first)
        {
            convert_binary(a1[i].second);
            int s = ans.size();
            while (s++ < n/2)
                cout << "0";
            for (int j = 0 ; j < ans.size() ; ++j)
                cout << ans[j];
            ans.clear();
            convert_binary(a2[k].second);
            s = ans.size();
            while (s++ < (n + 1) / 2)
                cout << "0";
            for (int j = 0 ; j < ans.size() ; ++j)
                cout << ans[j];
            break;
        }
    }
}