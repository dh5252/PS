#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;


int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    long long res = (long long)(b.first - a.first) * (c.second - b.second) - (long long)(c.first - b.first) * (b.second - a.second);

    if (res > 0)
        return 1;
    else if (res < 0)
        return -1;
    return 0;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);


    pair<int, int> a, b, c, d;

    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

    int res1 = ccw(a, b, c) * ccw(a, b, d);
    int res2 = ccw(c, d, a) * ccw(c, d, b);

    if (res1 <= 0 && res2 <= 0)
    {
        if (res1 == 0 && res2 == 0)
        {
            if (a > b)
                swap(a, b);
            if (c > d)
                swap(c, d);
            if (d >= a && c <= b)
                cout << 1;
            else
                cout << 0;
        }
        else
            cout << 1;
    }
    else
        cout << 0;


}