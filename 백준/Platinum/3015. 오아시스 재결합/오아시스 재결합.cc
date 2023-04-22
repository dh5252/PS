#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

#define MS 500001

int stack[MS];
int top = MS;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    long long cnt = 0;

    int tmp;
    cin >> tmp;
    stack[--top] = tmp;

    for (int i = 1 ; i < N ; ++i)
    {
        cin >> tmp;
        int k = upper_bound(stack + top, stack + MS, tmp) - stack;
        int l = lower_bound(stack + top, stack + MS, tmp) - stack;
        cnt += k - top + (k != MS);
        top = l;
        stack[--top] = tmp;
    }
    cout << cnt;
}