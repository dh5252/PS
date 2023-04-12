#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <set>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

int check[26];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    char str[53];
    int order[53];

    
    for (int i = 0; i < 52; ++i)
    {
        cin >> str[i];
        if (check[str[i] - 'A'] == 0)
        {
            order[i] = 1;
            check[str[i] - 'A']++;
        }
        else if (check[str[i] - 'A'] == 1)
        {
            order[i] = 2;
            check[str[i] - 'A']++;
        }
    }
    int cnt = 0;

    for (int i = 0; i < 52; ++i)
    {
        int find[26];
        memset(find, 0, sizeof(find));
        if (order[i] == 1)
        {
            for (int j = i + 1; str[j] != str[i]; ++j)
            {
                find[str[j] - 'A'] = order[j];
            }
            for (int j = 0; j < 26; ++j)
            {
                if (find[j] & 1)
                    ++cnt;
            }

        }
    }
    cout << cnt;
    
    return 0;
}