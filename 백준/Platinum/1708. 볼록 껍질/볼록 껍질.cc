#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <limits.h>

using namespace std;

typedef struct angle
{
    pair<int, int> d;
    long double cline;
}angle;

bool operator<(const angle& a, const angle& b)
{
    if (a.cline >= 0 && b.cline >= 0)
    {
        if (a.cline == b.cline) return a.d.second < b.d.second;
        return a.cline < b.cline;
    }
    if (a.cline < 0 && b.cline < 0)
    {
        if (a.cline == b.cline) return a.d.second > b.d.second;
        return a.cline < b.cline;
    }
    return a.cline > b.cline;
}

pair<int, int> dot[100001];
vector<angle> ang;


int ccw(pair<int, int>& a, pair<int, int>& b, pair<int, int> &c)
{
    long long res = (long long)(b.second - a.second) * (c.first - b.first) - (long long)(c.second - b.second) * (b.first - a.first);
    
    if (res > 0) return 1;
    else if (res < 0) return -1;
    return 0;
}

pair<int, int> stk[100001];
int top = -1;

void push(pair<int, int> a)
{
    stk[++top] = a;
}

pair<int, int> pop()
{
    return stk[top--];
}


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    int min_index;
    int min_value = INT_MAX;
    for (int i = 0; i < N; ++i)
    {
        cin >> dot[i].first >> dot[i].second;
        if (min_value > dot[i].first)
        {
            min_value = dot[i].first;
            min_index = i;
        }
        else if (min_value == dot[i].first)
            if (dot[min_index].second > dot[i].second)
                min_index = i;
    }

    for (int i = 0; i < N; ++i)
    {
        if (min_index == i) continue;
        long double angle;
        angle = (long double)(dot[i].first - dot[min_index].first) / (dot[i].second - dot[min_index].second);
        ang.push_back({ dot[i] ,angle });
    }

    sort(ang.begin(), ang.end());

    ang.push_back({ dot[min_index], 0 });

    push(dot[min_index]);
    for (int i = 0; i < ang.size(); ++i)
    {
        if (top >= 1)
        {
            if (ccw(stk[top - 1], stk[top], ang[i].d) > 0)
                push(ang[i].d);
            else
            {
                pop();
                i--;
            }
        }
        else
            push(ang[i].d);
    }

    cout << top << "\n";

    
}