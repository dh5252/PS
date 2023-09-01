#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    int cost;
    int value;
}   node;


vector<int> con[10001];
int A[10001];
vector<node> s;
bool check[10001];
int sum;
int min_v;

void dfs(int index)
{
    if (check[index])
        return ;
    check[index] = true;
    sum += A[index];
    if (min_v > A[index])
        min_v = A[index];
    for (int i = 0 ; i < con[index].size() ; ++i)
        dfs(con[index][i]);
}

int main()
{
    int N, M, k; cin >> N >> M >> k;
    for (int i = 1 ; i <= N ; ++i)
        cin >> A[i];
    
    for (int i = 0 ; i < M ; ++i)
    {
        int v,w; cin >> v >> w;
        con[v].push_back(w);
        con[w].push_back(v);
    }

    for (int i = 1 ; i <= N ; ++i)
    {
        sum = 0;
        min_v = INT_MAX;
        dfs(i);
        if (sum && min_v != INT_MAX)
            s.push_back({min_v, sum});
    }

    int ans = 0;
    for (int i = 0 ; i < s.size() ; ++i)
        ans += s[i].cost;
    if (ans > k)
        cout << "Oh no";
    else
        cout << ans;
}