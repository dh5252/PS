#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

typedef struct jewel
{
    int M;
    int V;
}   jewel;

bool operator<(const jewel &a, const jewel &b)
{
    return a.V > b.V;
}

jewel j[300000];
multiset<int> bag;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, K;

    cin >> N >> K;

    for (int i = 0 ; i < N ; ++i)
    {
        cin >> j[i].M >> j[i].V;
    }
    sort(j, j + N);
    for (int i = 0 ; i < K ; ++i)
    {
        int tmp;
        cin >> tmp;
        bag.insert(tmp);
    }

    long long sum = 0;
    for (int i = 0 ; i < N ; ++i)
    {
        if (bag.empty())
            break;
        auto k = bag.lower_bound(j[i].M);
        if (k != bag.end())
        {
            sum += j[i].V;
            bag.erase(k);
        }
    }
    cout << sum;
}