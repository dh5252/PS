#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int A[1000000];
int dp[1000001];
int dp_idx[1000001];
int idx[1000000];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);


    cin >> N;
    for (int i = 0 ; i < N ; ++i)
        cin >> A[i];
    
    dp[0] = -2147483648;
    int max_len = 0;
    for (int i = 0 ; i < N ; ++i)
    {
        int k = lower_bound(dp, dp + max_len + 1, A[i]) - dp;
        if (k > max_len)
        {
            dp[k] = A[i];
            ++max_len;
        }
        else
            dp[k] = A[i];
        dp_idx[k] = i;
        idx[i] = k;
    }
    cout << max_len;
    
    int cur = idx[dp_idx[max_len]];
    vector<int> record;

    record.push_back(A[dp_idx[max_len]]);
    for (int i = dp_idx[max_len] ; i >= 0 ; --i)
    {
        if (idx[i] == cur - 1)
        {
            record.push_back(A[i]);
            --cur;
        }
    }
    cout << "\n";
    for (int i = record.size() - 1 ; i >= 0 ; --i)
    {
        cout << record[i] << " ";
    }
}