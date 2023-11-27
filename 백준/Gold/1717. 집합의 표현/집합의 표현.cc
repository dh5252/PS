#include <bits/stdc++.h>
using namespace std;

int N,M;
int parent[1000001];

int find(int i)
{
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int i, int j)
{
    int r1 = find(i);
    int r2 = find(j);

    if (r1 == r2)
        return ;
    parent[r1] = r2;
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >>N>>M;

    for (int i=0;i<=N;++i)
        parent[i] = i;

    for(int i = 0 ; i < M;++i)
    {
        int a,b,c; cin >>a>>b>>c;
        if (a == 0)
        {
            unionSet(b,c);
        }
        else
        {
            if (find(b) == find(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    
    return 0;
}
