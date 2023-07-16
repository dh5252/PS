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

int ans[10];

int dfs(int index, int before, int cnt, int ans_cnt)
{
    if (10 - index < 5 - ans_cnt) return 0;

    if (cnt == 3) return 0;

    if (index == 10) return 1;

    int sum = 0;
    
    for (int i = 1 ; i <= 5 ; ++i)
    {
        if (ans[index] == i)
        {
            if (i == before)
                sum += dfs(index + 1, before, cnt + 1, ans_cnt + 1);
            else
                sum += dfs(index + 1, i, 1, ans_cnt + 1);
        }
        else
        {
            if (i == before)
                sum += dfs(index + 1, before, cnt + 1, ans_cnt);
            else
                sum += dfs(index + 1, i, 1, ans_cnt);
        }
    }
    return sum;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    for (int i = 0 ; i < 10 ; ++i)
        cin >> ans[i];
    
    cout << dfs(0, -1, 1, 0);
}