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
#include <list>
#include <stack>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

int pi[5001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    string str; cin >> str;

    int real_max = 0;
    for (int k = 0; k < str.length() ; ++k)
    {
        int j = k;
        int max_v = 0;
        memset(pi, 0, sizeof(pi));
        for (int i = k + 1 ; i < str.length() ; ++i)
        {
            while (j > k && str[i] != str[j])
                j = pi[j - 1] + k;
            if (str[i] == str[j])
            {
                pi[i] = ++j - k;
                max_v = max(max_v, pi[i]);
            }
        }
        real_max = max(real_max, max_v);
    }
    cout << real_max;
    return 0;
}