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

int main(int argc, char** argv)
{

	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N; cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i + j < N)
				cout << "*";
		}
		cout << "\n";
	}


	return 0;
}