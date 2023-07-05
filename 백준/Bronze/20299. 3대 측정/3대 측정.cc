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

using namespace std;


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, K, L; cin >> N >> K >> L;

    vector<int> vec;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        if (a + b + c >= K)
        {
            if (a >= L && b >= L && c >= L)
            {
                vec.push_back(a);
                vec.push_back(b);
                vec.push_back(c);
                ++cnt;
            }
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
}

