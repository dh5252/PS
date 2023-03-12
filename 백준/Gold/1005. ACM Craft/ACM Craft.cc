#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct node
{
    int time;
    int in_degree;
    vector<int> child;
} node;

node nd[3001];
int dp[3001];
int queue[3001];
int front, rear;

inline void enqueue(int num)
{
    queue[front++] = num;
}

inline int dequeue()
{
    return queue[rear++];
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

	int T;  cin >> T;

    for (int t = 0 ; t < T ; ++t)
    {
        memset(nd, 0, sizeof(nd));
        memset(dp, 0, sizeof(dp));

        int N, K;   cin >> N >> K;
        for (int i = 1 ; i <= N ; ++i)
            cin >> nd[i].time;
        for (int i = 0 ; i < K ; ++i)
        {
            int s, e;
            cin >> s >> e;
            nd[s].child.push_back(e);
            ++nd[e].in_degree;
        }
        int W;  cin >> W;
        front = rear = 0;
        
        for (int i = 1 ; i <= N ; ++i)
            if (!nd[i].in_degree)
            {
                dp[i] = nd[i].time;
                enqueue(i);
            }

        while (front != rear)
        {
            int num = dequeue();
            for (int i = 0 ; i < nd[num].child.size() ; ++i)
            {
                --nd[nd[num].child[i]].in_degree;
                dp[nd[num].child[i]] = max(dp[nd[num].child[i]], dp[num] + nd[nd[num].child[i]].time);
                
                if (nd[nd[num].child[i]].in_degree == 0)
                    enqueue(nd[num].child[i]);
            }
            nd[num].child.clear();
        }
        cout << dp[W] << "\n";
    }



}