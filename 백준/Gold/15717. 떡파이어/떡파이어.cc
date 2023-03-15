#include <iostream>
#include <cstring>
#include <algorithm>

#define MOD 1000000007
using namespace std;

long long dac(long long x)
{
	if (x <= 1)
		return 2;
	long long k = dac(x >> 1);
	k %= MOD;
	long long ans = k * k;
	if (x & 1)
		ans <<= 1;
	return ans % MOD;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	long long N;


	cin >> N;

	if (N <= 1)
		cout << 1;
	else
		cout << dac(N - 1);
	

	return 0;
}