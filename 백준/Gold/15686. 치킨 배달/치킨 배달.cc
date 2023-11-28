#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int i,j;
}node;


int N,M;
int m[51][51];
vector<node> home;
vector<node> chi;

int dfs(int index, int state, int size)
{
    if (size > M)
        return INT_MAX;
    if (index == chi.size())
    {
        long long sum = 0;
        for(int j =0;j<home.size();++j)
        {
            int min_v = INT_MAX;
            for (int i = 0 ; i < index ; ++i)
                if (state&(1<<i))
                    min_v=min(min_v, abs(home[j].i-chi[i].i) + abs(home[j].j-chi[i].j)); 
            sum += min_v;
        }
        if (sum > INT_MAX)
            return INT_MAX;
        //cout << "check : " << sum << "\n";
        return sum;
    }
    return min(dfs(index + 1, state|(1<<index), size+1),dfs(index + 1, state,size));
}



int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        {
            cin>>m[i][j];
            if (m[i][j] == 2)
                chi.push_back({i,j});
            else if (m[i][j] == 1)
                home.push_back({i,j});
        }
    
    cout << dfs(0, 0, 0);


    return 0;
}
