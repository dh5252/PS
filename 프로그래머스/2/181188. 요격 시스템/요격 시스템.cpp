#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    int s,e;
    
}   node;

bool operator<(const node &a, const node &b)
{
    if (a.s == b.s)
        return a.e > b.e;
    return a.s < b.s;
}

node nd[500001];

int solution(vector<vector<int>> targets) {
    
    for (int i = 0 ; i <targets.size() ; ++i)
    {
        nd[i].s = targets[i][0];
        nd[i].e = targets[i][1];
    }
    sort(nd, nd + targets.size());
    
    int last = -1;
    int cnt = 0;
    for (int i = 0 ; i < targets.size() ;++i)
    {
        if (last <= nd[i].s)
        {
            cnt++;
            last = nd[i].e;
        }
        else if (nd[i].e <= last)
        {
            last = nd[i].e;
        }
    }
    return cnt;
}