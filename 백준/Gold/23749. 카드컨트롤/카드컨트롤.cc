#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <utility>

using namespace std;

int N;
int card, top_loc;
pair<int, int> queue[1000000];
int front, rear;

inline void enqueue(int cd, int level)
{
	queue[front].first = cd;
	queue[front++].second = level;
}

inline pair<int, int> dequeue()
{
	return queue[rear++];
}

inline bool check_win(int cd)
{
	int win_cnt = 0;
	for (int i = top_loc; i > 0; i >>= 2)
	{
		if ((cd & i) && !(cd & (i >> 1)))
			++win_cnt;
		else if (!(cd & i) && (cd & (i >> 1)))
			--win_cnt;
	}
	return (win_cnt > 0);
}

void print_2(int num)
{
	for (int i = top_loc; i >= 1; i >>= 1)
	{
		if (i & num)
			cout << "1";
		else
			cout << "0";
	}
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	cin >> N;

	char tmp;
	card = 1;
	for (int i = 0; i < (N << 1); ++i)
	{
		cin >> tmp;
		if (tmp == 'O')
			card = card << 1 | 1;
		else
			card <<= 1;
	}
	top_loc = 1 << ((N << 1) - 1);
	
	enqueue(card, 0);
	while (front != rear)
	{
		pair<int, int> cur = dequeue();
		if (check_win(cur.first))
		{
			cout << cur.second;
			return 0;
		}
		for (int i = (top_loc >> 1); i > 0; i >>= 1)
		{
			int tmp = cur.first;
			int save = i & cur.first;
			for (int j = (i << 1); j <= top_loc; j <<= 1)
			{
				if (j & tmp)
					tmp |= (j >> 1);
				
				else if (tmp & (j >> 1))
						tmp -= (j >> 1);
			}
			if (save)
				tmp |= top_loc;
			else if (tmp & top_loc)
					tmp -= top_loc;
			enqueue(tmp, cur.second + 1);
		}
	}
	return 0;
}