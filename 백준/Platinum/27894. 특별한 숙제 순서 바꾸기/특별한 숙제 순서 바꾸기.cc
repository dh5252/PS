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

int arr[100001];
int ans[100001];

bool is_sort(int index)
{
    if (ans[index] > ans[index - 1] && ans[index] > ans[index - 2] && ans[index - 1] > ans[index - 2])
        return 1;
    if (ans[index] < ans[index - 1] && ans[index] < ans[index - 2] && ans[index - 1] < ans[index - 2])
        return 1;
    return 0;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    for (int i = 0; i < N; ++i)
        cin >> ans[i];
    int flag = 0;
    for (int i = 2; i < N; ++i)
    {
        if (is_sort(i)) {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        for (int i = 0; i < N; ++i)
        {
            if (arr[i] != ans[i]) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        cout << "POSSIBLE\n";
    }
    else cout << "POSSIBLE\n";
}