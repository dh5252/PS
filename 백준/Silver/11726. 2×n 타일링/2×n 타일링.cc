#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <stdio.h>

using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);


long long dp[1000] = { 0 };



long long fibo(int i) {

	if (i == 1) return 1L;
	if (i == 2) return 2L;

	if (dp[i] > 0) return dp[i];

	dp[i] = fibo(i - 1) % 10007 + fibo(i - 2) % 10007;


	return dp[i];

}





int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;


	long long ans = fibo(n) % 10007;

	cout << ans;




	return 0;
}

			