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
	char bef; cin >> bef;
	cin >> bef;
	int flag = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		char cur;
		cin >> cur;
		if (bef == cur)
			flag = 1;
		cin >> cur;
		bef = cur;
	}
	if (flag)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}