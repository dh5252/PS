#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int ans_table[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
int input[100000];
int T, N;
int min_value;

void find_min(int index, int cnt, int arr[3])
{
	if (cnt == 3)
	{
		min_value = min(min_value, ans_table[(arr[0] ^ arr[1])] + ans_table[(arr[0] ^ arr[2])] + ans_table[(arr[1] ^ arr[2])]);
		return;
	}
	if (index == N)
		return;
	arr[cnt] = input[index];
	find_min(index + 1, cnt + 1, arr);
	find_min(index + 1, cnt, arr);
}


int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		cin >> N;
		string tmp;
		memset(input, 0, sizeof(input));
		for (int i = 0; i < N; ++i)
		{
			cin >> tmp;
			if (tmp[0] == 'E')
				input[i] += 8;
			if (tmp[1] == 'S')
				input[i] += 4;
			if (tmp[2] == 'T')
				input[i] += 2;
			if (tmp[3] == 'J')
				input[i] += 1;
		}
		if (N > 32)
			cout << "0\n";
		else
		{
			int arr[3];
			min_value = 2147483647;
			find_min(0, 0, arr);
			cout << min_value << "\n";
		}
	}

	return 0;
}