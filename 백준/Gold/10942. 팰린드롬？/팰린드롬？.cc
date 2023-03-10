#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M;
	int S, E;
	int arr[4003];
	int A[4003];

	cin >> N;
	for (int i = 0; i < (N << 1) + 1; ++i)
	{
		if (i & 1)
			cin >> arr[i];
		else
			arr[i] = -1;
	}

	memset(A, 0, sizeof(A));
	int max_j = 0, max_range = 0;
	
	for (int i = 0; i < (N << 1) + 1; ++i)
	{
		if (i > max_range)
		{
			for (int k = 1; k <= (N << 1); ++k)
			{
				if ((i - k >= 0) && (i + k <= (N << 1)) && (arr[i - k] == arr[i + k]))
					++A[i];
				else break;
			}
		}
		else
		{
			int sym = 2 * max_j - i;
			if (sym >= 0 && i + A[sym] < max_range)
				A[i] = A[sym];
			else
			{
				A[i] += max_range - i;
				for (int k = max_range - i + 1; k <= (N << 1); ++k)
				{
					if (i - k >= 0 && i + k <= (N << 1) && (arr[i - k] == arr[i + k]))
						++A[i];
					else break;
				}
			}
		}
		if (max_range < A[i] + i)
		{
			max_range = A[i] + i;
			max_j = i;
		}
	}
	
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> S >> E;
		S = 2 * (S - 1) + 1;
		E = 2 * (E - 1) + 1;
		int mid = (S + E) / 2;
		if (A[mid] >= E - mid)
			cout << "1\n";
		else
			cout << "0\n";
	}

}