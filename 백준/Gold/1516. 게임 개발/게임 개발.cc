#include <bits/stdc++.h>
using namespace std;


int N;
pair<pair<int, int>, vector<int>> nd[501];
int dist[501];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

   
    cin >> N;
    for(int i =1;i<=N;++i)
    {
        int num; cin>>num;
        nd[i].first.first = num;
        cin>>num;
        while (num != -1) {
            nd[num].second.push_back(i);
            nd[i].first.second++;
            cin >> num;
        }
    }
    queue<int> que;
    for (int i=1;i<=N;++i) {
        if (!nd[i].first.second)
        {
            que.push(i);
            dist[i] = nd[i].first.first;
        }
    }

    while (!que.empty()) {

        int cur = que.front();
        que.pop();


        for(int i =0;i<nd[cur].second.size();++i){
            dist[nd[cur].second[i]] = max(nd[nd[cur].second[i]].first.first + dist[cur],dist[nd[cur].second[i]]);
            if (--nd[nd[cur].second[i]].first.second == 0) {
                que.push(nd[cur].second[i]);
            }
        }
    }
    for(int i=1;i<=N;++i)
        cout << dist[i] << "\n";

    return 0;
}
