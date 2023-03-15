#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;


int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	long long A[100001];

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	sort(A, A + N);

	long long min_value = LLONG_MAX;
	for (int i = 0; i < N; ++i)
	{
		int first = lower_bound(A + i, A + N, A[i] + M) - A;
		if (first != N)
			min_value = min(min_value, A[first] - A[i]);
	}
	cout << min_value;
	
	return 0;
}