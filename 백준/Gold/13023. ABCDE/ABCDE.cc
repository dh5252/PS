#include <bits/stdc++.h>
using namespace std;

int v[2001];
int N, M;
int max_level;
vector<int> nd[2001];

void dfs(int i, int level) 
{
    if (level > max_level) max_level = level;
    if (level == 4) return ;

    v[i] = 1;

    for(int j = 0 ; j < nd[i].size() ; ++j) {
        if (!v[nd[i][j]]) {
            dfs(nd[i][j], level + 1);
            v[nd[i][j]] = 0;
        }
    }
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M;
    for(int i = 0 ; i < M ; ++i) {
        int a,b; cin>>a>>b;
        nd[a].push_back(b);
        nd[b].push_back(a);
    }

    for (int i = 0 ; i < N ; ++i) {
        memset(v, 0, sizeof(v));
        max_level = 0;
        dfs(i, 0);
        if (max_level >= 4){
            cout << 1;
            return 0;
        }
    }

    
    cout << 0;
    
    return 0;
}
