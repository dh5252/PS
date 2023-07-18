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

typedef struct sen
{
    int p;
    int c;
}   sen;

bool operator<(const sen &a, const sen &b)
{
    return a.p < b.p;
}

sen s[100001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    for (int i = 0 ; i < N ; ++i)
        cin >> s[i].p >> s[i].c;
    
    sort(s, s + N);
    int cur = s[0].c;
    long long sum = 0;
    for (int i = 1 ; i < N ; ++i)
    {
        if (cur > s[i].c)
            sum += cur - s[i].c;
        cur = s[i].c;
    }
    sum += s[N - 1].c;
    cout << sum;
}