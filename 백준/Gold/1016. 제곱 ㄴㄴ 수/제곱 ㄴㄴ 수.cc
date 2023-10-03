#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;



vector<long long> findPrimeNumbers(long long max) { // 에라토스테네스의 체. 범위까지 소수 찾기

	
	vector<long long> primePow;

	bool prime[1000001] = {0};

	prime[1] = false;

	for (long long i = 2; i * i <= max; i++) {
		if (!prime[i]) {
			for (long long j = 2; i * j * i * j <= max; j++) {
				prime[i * j] = 1;
			}
			primePow.push_back(i * i);
		}
	}

	return primePow;	// 소수의 제곱 저장

}

int countPowNoNoNumber(long long min_v, long long max_v, vector<long long> &primePow) { //	제곱 ㄴㄴ수 찾기

	bool check[1000001] = {0};

    for (int i = 0 ; i < primePow.size() ; ++i)
    {
        long long init;

        if ((min_v / primePow[i]) * primePow[i] < min_v)
            init = min_v / primePow[i] * primePow[i] + primePow[i];
        else
            init = min_v;
        while (init <= max_v)
        {
            check[init - min_v] = 1;
            init += primePow[i];
        }
    }
     int cnt = 0;
    for (int i = 0 ; i <= max_v - min_v ; ++i)
    {
        if (check[i] == 0)
            ++cnt;
    }
    return cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long min_v, max_v;
	double primeRangeMax;

	vector<long long> primePow;

	cin >> min_v >> max_v;

	primePow = findPrimeNumbers(max_v);

	cout << countPowNoNoNumber(min_v, max_v, primePow);
}