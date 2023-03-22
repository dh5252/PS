#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <utility>
#include <queue>

using namespace std;

typedef struct dot
{
	int x, y;
}	dot;

typedef struct line
{
	dot d1, d2;
}	line;

line ln[3000];
int parent[3000];
int hei[3000];
int desc_cnt[3000];
int group_cnt;

bool operator<(const dot& a, const dot& b)
{
	if (a.x < b.x)
		return 1;
	else if (a.x == b.x)
		if (a.y > b.y)
			return 1;
	return 0;
}

int find(int cur)
{
	if (cur == parent[cur])
		return cur;
	return parent[cur] = find(parent[cur]);
}

void set_union(int a, int b)
{
	int r1 = find(a);
	int r2 = find(b);

	if (r1 == r2)
		return;
	--group_cnt;
	if (hei[r1] < hei[r2])
	{
		parent[r1] = r2;
		desc_cnt[r2] += desc_cnt[r1];
	}
	else if (hei[r1] > hei[r2])
	{
		parent[r2] = r1;
		desc_cnt[r1] += desc_cnt[r2];
	}
	else
	{
		parent[r2] = r1;
		++hei[r1];
		desc_cnt[r1] += desc_cnt[r2];
	}
}


int ccw(dot a, dot b, dot c)
{
	long long res = (long long)(a.x - c.x) * (b.y - a.y) - (long long)(a.y - c.y) * (b.x - a.x);

	if (res > 0)
		return 1;
	if (res < 0)
		return -1;
	return 0;
}

int check(line a, line b)
{
	int res1 = ccw(a.d1, b.d1, b.d2) * ccw(a.d2, b.d1, b.d2);
	int res2 = ccw(b.d1, a.d1, a.d2) * ccw(b.d2, a.d1, a.d2);

	pair<int, int> p1 = make_pair(a.d1.x, a.d1.y);
	pair<int, int> p2 = make_pair(a.d2.x, a.d2.y);
	pair<int, int> p3 = make_pair(b.d1.x, b.d1.y);
	pair<int, int> p4 = make_pair(b.d2.x, b.d2.y);
					 
	if (res1 <= 0 && res2 <= 0)
	{
		if (res1 == 0 && res2 == 0)
		{
			if (p1 > p2)
				swap(p1, p2);
			if (p3 > p4)
				swap(p3, p4);
			return p1 <= p4 && p3 <= p2;
		}
		return 1;
	}
	return 0;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;

	cin >> N;
	group_cnt = N;
	for (int i = 0; i < N; ++i)
		parent[i] = i;
	for (int i = 0; i < N; ++i)
	{
		cin >> ln[i].d1.x >> ln[i].d1.y >> ln[i].d2.x >> ln[i].d2.y;
		desc_cnt[i] = 1;
		for (int j = 0; j < i; ++j)
			if (check(ln[i], ln[j]))
				set_union(i, j);
	}

	int max_group = 0;
	for (int i = 0; i < N; ++i)
		max_group = max(max_group, desc_cnt[i]);
	
	cout << group_cnt << "\n" << max_group;
	
	return 0;
}