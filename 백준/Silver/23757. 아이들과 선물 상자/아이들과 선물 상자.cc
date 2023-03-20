#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <utility>
#include <queue>

using namespace std;

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	priority_queue<int> pq;

	int N, M;
	int child_want[100001];

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	for (int i = 0; i < M; ++i)
		cin >> child_want[i];
	
	for (int i = 0; i < M; ++i)
	{
		int top = pq.top();
		pq.pop();
		if (top < child_want[i])
		{
			cout << 0;
			return 0;
		}
		pq.push(top - child_want[i]);
	}
	cout << 1;
	return 0;
}