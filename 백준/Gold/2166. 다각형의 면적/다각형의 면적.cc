#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

pair<double, double> coordi[10000];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> coordi[i].first >> coordi[i].second;
    }

    double sum = 0;
    for (int i = 1; i < N - 1; ++i)
    {
        sum += ((coordi[i].first - coordi[0].first) * (coordi[i + 1].second - coordi[0].second) - (coordi[i + 1].first - coordi[0].first) * (coordi[i].second - coordi[0].second)) / 2;
    }
    if (sum < 0)
        sum *= -1;
    cout.precision(1);
    cout << fixed;
    cout << sum;
}