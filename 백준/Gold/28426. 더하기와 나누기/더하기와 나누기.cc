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
#include <unordered_set>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;

    cout << 2 << " ";
    for (int i = 1 ; i < N ; ++i)
    {
        cout << i * 4 << " ";
    }
}