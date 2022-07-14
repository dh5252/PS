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


int returnMinCalculation(vector<int>& dp, int currentNum, int cnt) {

	if (currentNum == 1) return cnt;


	if (dp[currentNum] > 0) return cnt + dp[currentNum];
	


	int min = 999999999;
	int tmp;

	if (currentNum % 3 == 0) {
		min = returnMinCalculation(dp, currentNum / 3, cnt + 1) ;
	}

	if (currentNum % 2 == 0) {
		tmp = returnMinCalculation(dp, currentNum / 2, cnt + 1);
		min = min > tmp ? tmp : min;
	}


	if (currentNum % 6 != 0) {
		tmp = returnMinCalculation(dp, currentNum -1, cnt + 1) ;
		min = min > tmp ? tmp : min;
	}


	dp[currentNum] = min - cnt;


	return min;
}







int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;

	cin >> N;

	vector<int> dp(N + 1, 0);

	cout << returnMinCalculation(dp, N, 0);



	return 0;
}

			