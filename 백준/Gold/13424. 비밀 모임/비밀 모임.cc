#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;

typedef struct room{
    int con;
    int dist;
} room;

bool operator<(const room& a, const room& b)
{
    return a.dist < b.dist;
}

vector<room> graph[101];

priority_queue<room> pq;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N, M;
        cin >> N >> M;

        int min_sum = 2147483647;
        int min_room = -1;
        memset(graph, 0, sizeof(graph));
        pq = {};

        for (int i = 0; i < M; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({ b,c });
            graph[b].push_back({ a,c });
        }
        int K; cin >> K;
        int arrive[101] = { 0 };
        for (int i = 0; i < K; ++i)
        {
            int tmp;
            cin >> tmp;
            arrive[tmp] = 1;
        }
        
        for (int i = 1; i <= N; ++i)
        {
            int table[101];
            for (int j = 1; j <= N; ++j)
                table[j] = INT_MAX;

            table[i] = 0;
            
            pq.push({ i, 0 });
            while (!pq.empty())
            {
                room cur = pq.top();
                pq.pop();

                for (int j = 0; j < graph[cur.con].size(); ++j)
                {
                    if (table[graph[cur.con][j].con] > cur.dist + graph[cur.con][j].dist)
                    {
                        table[graph[cur.con][j].con] = cur.dist + graph[cur.con][j].dist;
                        pq.push({ graph[cur.con][j].con, cur.dist + graph[cur.con][j].dist });
                    }
                }
            }
            int sum = 0;
            for (int j = 1; j <= N; ++j)
            {
                if (arrive[j])
                    sum += table[j];
            }
            if (min_sum > sum)
            {
                min_sum = sum;
                min_room = i;
            }
        }
        cout << min_room << "\n";
    }

    
    
}