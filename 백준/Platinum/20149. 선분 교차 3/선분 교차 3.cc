#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;


int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c)
{
    long long res = (b.first - a.first) * (c.second - b.second) - (c.first - b.first) * (b.second - a.second);

    if (res > 0)
        return 1;
    else if (res < 0)
        return -1;
    return 0;
}

inline double cline(pair<long long, long long> a, pair<long long, long long> b)
{
    if ((a.first - b.first) == 0)
        return 293487523453;
    return (double)(a.second - b.second) / (a.first - b.first);
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);


    pair<long long, long long> a, b, c, d;

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
            {
                cout << 1 << "\n";
                if (d == a)
                    cout << d.first << " " << d.second;
                else if (c == b)
                    cout << c.first << " " << c.second;
                else if (b == d && cline(a, b) != cline(c, d))
                    cout << b.first << " " << b.second;
                else if (a == c && cline(a, b) != cline(c, d))
                    cout << a.first << " " << a.second;    
            }
            else
                cout << 0;
        }
        else
        {
            cout << 1 << "\n";
            long double c1 = (long double)(b.second - a.second) / (a.first - b.first) * a.first + a.second;
            long double c2 = (long double)(d.second - c.second) / (c.first - d.first) * c.first + c.second;

            long double x = (-c.first * (d.second - c.second) * (b.first - a.first) + a.first * (b.second - a.second) * (d.first - c.first) + (d.first - c.first) * (b.first - a.first) * (c.second - a.second));
            long double y;
            
            x /= ((b.second - a.second) * (d.first - c.first) - (d.second - c.second) * (b.first - a.first));
            if (c.first == d.first)
                y = (long double)(b.second - a.second) / (b.first - a.first) * x + c1;
            else
                y = (long double)(d.second - c.second) / (d.first - c.first) * x + c2;
            cout << fixed;
            cout.precision(16);
            cout << x << " " << y;
                   

        }
    }
    else
        cout << 0;


}