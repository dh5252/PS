#include <bits/stdc++.h>
using namespace std;

// s가 last보다 크다면 선택 last 갱신
// e가 전꺼보다 작다면? 선택 cnt 그대로
// 크거나 같다면 무시

typedef struct node {
    int s,e;
}   node;

bool operator<(const node &a, const node &b) {
    if (a.s == b.s)
        return a.e < b.e;
    return a.s < b.s;
}

int N;
node nd[100001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0 ; i < N ; ++i)
        cin >> nd[i].s >> nd[i].e;
    sort(nd, nd + N);
    int cnt = 0;
    int last = -1;
    for (int i = 0 ; i < N ; ++i) {
        if (nd[i].s >= last) {
            cnt++;
            last = nd[i].e;
            //cout << "check : " << last << "\n";
        }
        else if (nd[i].e < last)
            last = nd[i].e;
    }
    cout << cnt;
}

