#include <iostream>
#include <algorithm>
using namespace std;


int combination(int M, int N) {
	double ans = 1;

	for (int i = 1; i <= N; i++) {
		ans *= M - N + i;
		ans /= i;
	}

	return (int)ans;


} //M combination N


int main() {
	
	int T;
	int N, M;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> T;

	// M개의 구슬에서 순서 있이 N개를 뽑기. M combination N

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cout << combination(M, N) << "\n";
	}



}