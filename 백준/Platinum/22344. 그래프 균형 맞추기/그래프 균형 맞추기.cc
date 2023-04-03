#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

vector<pair<long long, long long> > node[200001];
bool visit[200001];

pair<long long, long long> graph[200001];
int fail_flag;
int flag;
long long x;

long long cnt = 0;
long long save = 0;


void dfs(long long node_num)
{
    if (fail_flag == 1)
        return;
    
    visit[node_num] = 1;
    if (cnt >= save)
    {
        ++cnt;
        for (long long i = 0 ; i < node[node_num].size() ; ++i)
            if (!visit[node[node_num][i].first])
            {
                graph[node[node_num][i].first] = { -graph[node_num].first, node[node_num][i].second - graph[node_num].second };
                if (x)
                {
                    long long s1 = graph[node_num].first * x + graph[node_num].second;
                    long long s2 = graph[node[node_num][i].first].first * x + graph[node[node_num][i].first].second;

                    if (s1 + s2 != node[node_num][i].second)
                    {
                        fail_flag = 1;
                        return;
                    }
                }
                dfs(node[node_num][i].first);
            }
            else if (graph[node[node_num][i].first].first != graph[node_num].first)
            {
                if (node[node_num][i].second != graph[node[node_num][i].first].second + graph[node_num].second)
                {
                    fail_flag = 1;
                    return;
                }
            }
            else
            {
                flag = 1;
                if (!x)
                    if ((graph[node[node_num][i].first].second + graph[node_num].second - node[node_num][i].second) % (graph[node[node_num][i].first].first + graph[node_num].first) == 0)
                        x = -(double)(graph[node[node_num][i].first].second + graph[node_num].second - node[node_num][i].second) / (graph[node[node_num][i].first].first + graph[node_num].first);
                    else
                        fail_flag = 1;
                save = cnt;
                return;
            }
        return;
    }
    ++cnt;
    for (long long i = 0; i < node[node_num].size(); ++i)
    {
        long long s1 = graph[node_num].first * x + graph[node_num].second;
        long long s2 = graph[node[node_num][i].first].first * x + graph[node[node_num][i].first].second;

        if (s1 + s2 != node[node_num][i].second)
        {
            fail_flag = 1;
            return;
        }
    }

}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    long long N, M;

    cin >> N >> M;
    for (long long i = 0; i < M; ++i)
    {
        long long a, b, wei;

        cin >> a >> b >> wei;
        node[a].push_back({ b, wei });
        node[b].push_back({ a, wei });
    }

    graph[1] = { 1, 0 };
    dfs(1);

    if (fail_flag)
    {
        cout << "No\n";
        return 0;
    }

    if (flag)
    {
        memset(visit, 0, sizeof(visit));
        dfs(1);
        if (fail_flag)
        {
        
            cout << "No\n";
            return 0;
        }
        cout << "Yes\n";
        for (long long i = 1; i <= N; ++i)
            if (visit[i])
                cout << graph[i].first * x + graph[i].second << " ";
        return 0;
    }

    long long sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (graph[i].first == 1)
            sum += -graph[i].second;
        else if (graph[i].first == -1)
            sum += graph[i].second;
    }

    long long min1 = ceil((double)sum / N);
    long long min2 = floor((double)sum / N);

    int s1 = 0;
    int s2 = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (!visit[i])
            continue;
        s1 += ABS(graph[i].first * min1 + graph[i].second);
        s2 += ABS(graph[i].first * min2 + graph[i].second);
    }

    cout << "Yes\n";
    if (s1 < s2)
        for (int i = 1; i <= N; ++i)
        {
            if (!visit[i])
                continue;
            cout << graph[i].first * min1 + graph[i].second << " ";
        }
    else
        for (int i = 1; i <= N; ++i)
        {
            if (!visit[i])
                continue;
            cout << graph[i].first * min2 + graph[i].second << " ";
        }

    /*
    long long min_v = LLONG_MAX, max_v = LLONG_MIN;
    for (long long i = 1; i <= N; ++i)
    {
        if (graph[i].first == 1)
        {
            min_v = min(min_v, -graph[i].second);
            max_v = max(max_v, graph[i].second);
        }
        else if (graph[i].first == -1)
        {
            min_v = min(min_v, -graph[i].second);
            max_v = max(max_v, graph[i].second);
        }
    }

    long long Min = LLONG_MAX;

    for (long long k = min_v; k <= max_v; ++k)
    {
        long long s = 0;
        for (long long i = 1; i <= N; ++i)
        {
            if (!visit[i])
                continue;
            s += ABS(graph[i].first * k + graph[i].second);
        }
        if (Min > s)
        {
            Min = s;
            x = k;
        }
    }
    cout << "Yes\n";
    for (long long i = 1; i <= N; ++i)
    {
        if (!visit[i])
            continue;
        cout << graph[i].first * x + graph[i].second << " ";
    }
    */
}