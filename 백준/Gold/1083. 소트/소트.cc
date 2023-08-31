#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#pragma warning(disable:4996)

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

int main()
{

	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N; cin >> N;
	int arr[51];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	int S; cin >> S;
	int max_v;
	int max_idx;
	for (int i = 0; i < N; ++i)
	{
		max_v = 0;
		max_idx = -1;
		for (int j = i; j < N && j - i <= S; ++j)
		{
			if (max_v < arr[j])
			{
				max_v = arr[j];
				max_idx = j;
			}
		}
		for (int j = max_idx; j > i; --j)
		{
			swap(arr[j], arr[j - 1]);
			if (--S == 0)
				break;
		}
		if (S == 0) break;
	}
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
}