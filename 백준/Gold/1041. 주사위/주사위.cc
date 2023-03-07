#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

	long long N;
	int dice[6];
	long long sum = 0;

	cin >> N;
	for (int i = 0; i < 6; ++i)
		cin >> dice[i];

	if (N == 1)
	{
		for (int i = 0; i < 6; ++i)
			sum += dice[i];
		int max_dice = 0;
		for (int i = 0 ; i < 6 ; ++i)
			max_dice = max(max_dice, dice[i]);
		cout << sum - max_dice << "\n";
	}

    else
    {
        long long min_one, min_two, min_three;
        dice[0] = min(dice[0], dice[5]);
        dice[1] = min(dice[1], dice[4]);
        dice[2] = min(dice[2], dice[3]);

        sort(dice, dice + 3);

        min_one = dice[0];
        min_two = dice[0] + dice[1];
        min_three = min_two + dice[2];


        sum += min_one * (5 * N * N - 16 * N + 12);
        sum += min_two * ((N << 3) - 12);
        sum += min_three << 2;

        cout << sum << "\n";
    }
    return 0;
}