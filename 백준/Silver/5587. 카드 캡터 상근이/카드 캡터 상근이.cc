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

int a[101];
int b[101];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int index = 0;
    int index2 = 0;
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (i != a[index]) b[index2++] = i;
        else index++;
    }
    sort(b, b + n);

    
    int i = 0;
    int j = 0;
    bool visit1[101] = {0};
    bool visit2[101] = {0};
    int flag2 = 0;
    while (1)
    {  
        int flag = 0;
        if (!flag2)
        {
            visit1[i] = 1;
            for (int k = 0; k < n; ++k)
                if (!visit1[k]) flag = 1;
            if (!flag) break;
            while (j < n && (visit2[j] || b[j] < a[i])) j++;
            if (j == n)
            {
                for (int k = 0 ; k < n ; ++k)
                    if (!visit1[k])
                    {
                        i = k;
                        j = 0;
                        break;
                    }
                continue;
            }

        }
        visit2[j] = 1;
        flag = 0;
        for (int k = 0; k < n; ++k)
            if (!visit2[k]) flag = 1;
        if (!flag) break;
        while (i < n && (visit1[i] || a[i] < b[j])) i++;
        if (i == n)
        {
            for (int k = 0; k < n; ++k)
                if (!visit2[k])
                {
                    j = k;
                    i = 0;
                    break;
                }
            flag2 = 1;
        }
        else flag2 = 0;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!visit1[i]) ++cnt1;
        if (!visit2[i]) ++cnt2;
    }
    cout << cnt2 << "\n" << cnt1;
}

