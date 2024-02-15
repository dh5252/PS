#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int s1,s2;
}   node;

bool operator<(const node &a, const node &b) {
    return a.s1 < b.s1;
}

node nd[100000];
int max_v[100000];
int sum_score[100000];
int N;
int std_score;
int std1, std2;

int solution(vector<vector<int>> scores) {
    N = scores.size();
    for (int i = 0 ; i < scores.size() ; ++i) {
        nd[i].s1 = scores[i][0];
        nd[i].s2 = scores[i][1];
    }
    std1 = nd[0].s1;
    std2 = nd[0].s2;
    std_score = nd[0].s1 + nd[0].s2;
    sort(nd, nd + N);
    int m = 0;
    for (int i = N - 1 ; i >= 0 ; --i)  {
        max_v[i] = m = max(m, nd[i].s2);
        sum_score[i] = nd[i].s1 + nd[i].s2;
    }
    
    for (int i = 0 ; i < N ; ++i) {
        int k = upper_bound(nd + i, nd + N, nd[i]) - nd;
        if (k == N)
            continue;
        if (nd[i].s2 < max_v[k])
            sum_score[i] = -1;
    }
    
    for (int i = 0 ; i < N ; ++i) {
        if (std1 < nd[i].s1 && std2 < nd[i].s2)
            return -1;
    }
    
    
    int ans = 1;
    for (int i = 0 ; i < N ; ++i) {
        if (std_score < sum_score[i])
            ++ans;
    }
    return ans;
}