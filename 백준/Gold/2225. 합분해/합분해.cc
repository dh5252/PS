#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
using namespace std;


//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

// 칸막이 개념! 만약 N이 5고 K가 2라고 해보자.
//  ^ㅁ^ㅁ^ㅁ^ㅁ^ㅁ^
// ^ 위치에 칸막이가 "중복"으로 1개 들어가면 문제의 조건을 완벽하게 맞춘다.

// 조합 공식이용. nCr = n-1Cr-1 + n-1Cr

long long combination(int n, int r) {
	
    long long** combination;
    long long answer;

    combination = (long long**)malloc(sizeof(long long*) * (n + 1));
    for (int i = 0; i < n + 1; i++)
        combination[i] = (long long*)malloc(sizeof(long long) * (i + 1));

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j <= i && j != r + 1; j++) {
            if (i == j || j == 0) combination[i][j] = 1;
            else combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j])%1000000000;
        }
    }
    answer = combination[n][r];

    for (int i = 0; i < n + 1; i++) free(combination[i]);
    free(combination);

    return answer;
}

//중복조합 공식이용
long long combinationWithRepetition(int n, int r) {
	return  combination(n + r - 1, r);
}




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K;

	cin >> N >> K;

	cout << combinationWithRepetition(N + 1, K - 1)%1000000000  << endl;

	


}

			