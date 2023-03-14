#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

#define ABS(x) (((x) < 0) ? -(x):(x))
#define parent (i >> 1)
#define left (i << 1)
#define right (i << 1 | 1)

using namespace std;

typedef struct vertice
{
    int x, y, z;
    vector<pair<int, int>> connect;
}   vertice;

typedef struct coordi
{
    int value;
    int origin_index;
}    coordi;

vertice ver[100001];
int visit[100001];
coordi x[100001];
coordi y[100001];
coordi z[100001];

pair<int, int> heap[10000000];
int heap_size;

// x, y, z 순으로 정렬, 문제 특성이용
void push_heap(pair<int, int> insert)
{
    heap[++heap_size] = insert;
    for (int i = heap_size; parent != 0 && heap[parent].second > heap[i].second; i >>= 1)
    {
        pair<int, int> tmp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = tmp;
    }
}

pair<int, int> pop_heap()
{
    pair<int, int> tmp = heap[1];
    heap[1] = heap[heap_size--];
    for (int i = 1; left <= heap_size; )
    {
        if (left == heap_size || heap[left].second < heap[right].second)
        {
            if (heap[i].second > heap[left].second)
            {
                pair<int, int> tmp2 = heap[i];
                heap[i] = heap[left];
                heap[left] = tmp2;
                i = left;
            }
            else
                break;
        }
        else
        {
            if (heap[i].second > heap[right].second)
            {
                pair<int, int> tmp2 = heap[i];
                heap[i] = heap[right];
                heap[right] = tmp2;
                i = right;
            }
            else break;
        }
    }
    return tmp;
}
//힙 직접 구현해야함.

bool operator<(const coordi& a, const coordi& b)
{
    return a.value < b.value;
}


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> ver[i].x >> ver[i].y >> ver[i].z;
        x[i].value = ver[i].x;
        x[i].origin_index = i;
        y[i].value = ver[i].y;
        y[i].origin_index = i;
        z[i].value = ver[i].z;
        z[i].origin_index = i;
    }

    sort(x, x + N);
    sort(y, y + N);
    sort(z, z + N);

    for (int i = 1; i < N; ++i)
    {
        ver[x[i].origin_index].connect.push_back(make_pair(x[i - 1].origin_index, x[i].value - x[i - 1].value));
        ver[x[i - 1].origin_index].connect.push_back(make_pair(x[i].origin_index, x[i].value - x[i - 1].value));

        ver[y[i].origin_index].connect.push_back(make_pair(y[i - 1].origin_index, y[i].value - y[i - 1].value));
        ver[y[i - 1].origin_index].connect.push_back(make_pair(y[i].origin_index, y[i].value - y[i - 1].value));

        ver[z[i].origin_index].connect.push_back(make_pair(z[i - 1].origin_index, z[i].value - z[i - 1].value));
        ver[z[i - 1].origin_index].connect.push_back(make_pair(z[i].origin_index, z[i].value - z[i - 1].value));
    }
    int cnt = 0;
    long long min_cost = 0;
    push_heap(make_pair(0, 0));
    while (heap_size != 0)
    {
        pair<int, int> cur = pop_heap();
        if (visit[cur.first])
            continue;
        //cout << "check : " << cur.first << " " << cur.second << "\n";
        min_cost += cur.second;
        visit[cur.first] = 1;
        if (++cnt == N)
            break;
        for (int i = 0; i < ver[cur.first].connect.size() ; ++i)
            if (ver[cur.first].connect[i].first != cur.first && !visit[ver[cur.first].connect[i].first])
            {
                push_heap(ver[cur.first].connect[i]);
                //cout << i << ": " << min(ABS(ver[i].x - ver[cur.first].x), min(ABS(ver[i].y - ver[cur.first].y), ABS(ver[i].z - ver[cur.first].z))) << "\n";
            }
    }
    cout << min_cost;
}