#include <bits/stdc++.h>

using namespace std;

int w[5][21];
vector<pair<int, int>> t[5]; 
int K, N;

long long dfs(int lv, int cnt) {
    
    if (lv == K)
        return 0;
    
    long long m = INT_MAX;
    for (int i = 1 ; i + cnt <= N ; ++i) {
        m = min(m, dfs(lv + 1, i + cnt) + w[lv][i]);
        if (!w[lv][i]) break;
    }
    return m;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    
    for (int i = 0 ; i < reqs.size() ; ++i) {
        t[reqs[i][2] - 1].push_back({reqs[i][0], reqs[i][1]});
    }
    
    for (int i = 0 ; i < k ; ++i) {
        for (int j = 1 ; j <= n ; ++j) {
            int cnt = 0;
            int wait = 0;
            priority_queue<int> fin_que;
            for (int req = 0 ; req < t[i].size() ; ++req) {
                
                
                while (!fin_que.empty() && -fin_que.top() <= t[i][req].first) {
                    fin_que.pop();
                    --cnt;
                }
                    
                if (cnt < j) {
                    fin_que.push(-(t[i][req].second + t[i][req].first));
                    cnt++;
                    continue;
                }
                int cur = -fin_que.top();
                wait += cur - t[i][req].first;
                fin_que.pop();
                fin_que.push(-(cur + t[i][req].second));
            }
            w[i][j] = wait;
        }
    }
    
    for (int i = 0 ; i < k ; ++i) {
        for (int j = 1 ; j <= n ; ++j)
            cout << w[i][j] << " ";
        cout << "\n";
    }
    
    
    K = k;
    N = n;
    return dfs(0, 0);
}