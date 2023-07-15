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
#include <list>

using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, X; cin >> N >> X;
    for (int i = 0; i < N; ++i)
    {
        int in; cin >> in;
        if (in < X) cout << in << " ";
    }



}
