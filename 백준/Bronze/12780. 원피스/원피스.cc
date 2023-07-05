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

using namespace std;

string H, N;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> H;
    cin >> N;

    int cnt = 0;
    for (int i = 0; i <= H.length() - N.length(); ++i)
    {
        int flag = 0;
        for (int j = 0; j < N.length(); ++j)
        {
            if (i + j >= H.length()) break;
            if (H[i + j] != N[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag) ++cnt;
    }
    cout << cnt;
}

