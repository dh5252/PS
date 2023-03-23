#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct line
{
    int a,b;
}   line;

bool operator<(const line &l1, const line &l2)
{
    return l1.a < l2.a;
}

int dp[100001];
int idx[100001];

int rec[100001];
line ln[100000];
int islis[500001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0 ; i < N ; ++i)
        cin >> ln[i].a >> ln[i].b;
    
    sort(ln, ln + N);

    int max_len = 0;
    vector<int> del;
    for (int i = 0 ; i < N ; ++i)
    {
        int k = lower_bound(dp, dp + max_len + 1, ln[i].b) - dp; 
        if (k > max_len)
        {
            idx[k] = i;
            dp[k] = ln[i].b;
            rec[i] = k;
            ++max_len;
        }
        else
        {
            idx[k] = i;
            dp[k] = ln[i].b;
            rec[i] = k;
        }
    } 
    cout << N - max_len << "\n";

    int cur = rec[idx[max_len]];
    islis[idx[max_len]] = 1;
    for (int i = idx[max_len] ; i >= 0 ; --i)
    {
        if (cur - 1 == rec[i])
        {
            cur = rec[i];
            islis[i] = 1;
        }
    }

    for (int i = 0 ; i < N ; ++i)
    {
        if (!islis[i])
            cout << ln[i].a << "\n";
    }
}