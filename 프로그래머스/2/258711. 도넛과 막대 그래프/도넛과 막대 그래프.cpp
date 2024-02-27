#include <bits/stdc++.h>

using namespace std;

vector<int> nd[1000001];
int indegree[1000001];
bool v[1000001];

int check(int ver) {

    if (indegree[ver] > 1) return 3; // eight
    
    if (v[ver]) {
        return 2; // circle
    }
    v[ver] = 1;
    
    int res = 1;
    for (int i = 0 ; i < nd[ver].size() ; ++i)
        res = max(res, check(nd[ver][i]));
    return res; // stick
}


vector<int> solution(vector<vector<int>> edges) {
    
    for (int i = 0 ; i < edges.size() ; ++i)  {
        nd[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;    
    }
        
    int ver;
    for (int i = 1 ; i <= 1000000; ++i)  {
        if (nd[i].size() >= 2 && !indegree[i])
        {
            ver = i;
            break;
        }    
    }
    
    vector<int> ans(4, 0);
    ans[0] = ver;
    v[ver] = 1;
    for (int i = 0 ; i < nd[ver].size() ; ++i) {
        indegree[nd[ver][i]]--;
        ans[check(nd[ver][i])]++;
    }
    swap(ans[1], ans[2]);
    return ans;
}