#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    N = sequence.size();
    int s = 0, e = 0, cur = sequence[s];
    int cur_len = INT_MAX;
    pair<int,int> ans;
    while (!(s > N - 1 && e >= N - 1))
    {
        if (cur == k)
        {
            if (e - s < cur_len)
            {
                cur_len = e - s;
                ans = {s, e};
            }
            cur -= sequence[s++];
            cur += sequence[++e];
        }
        else if (cur > k || e == N - 1)
            cur -= sequence[s++];
        else if (cur < k)
            cur += sequence[++e];
    }
    answer.push_back(ans.first);
    answer.push_back(ans.second);
    return answer;
}