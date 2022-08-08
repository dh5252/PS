#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <stdio.h>
#include <list>
#include <math.h>
#include <map>

using namespace std;


int memo[1000000][101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int item[100][2];
	int N, K;

	
	for (int j = 0; j <= 1000; j++) {
		memo[j][0] = 0;
	}
	for (int j = 0; j <= 100; j++) {
		memo[0][j] = 0;
	}




		cin >> N >> K;

		for (int j = 1; j <= N; j++) {
			cin >> item[j][0] >> item[j][1];
		}

		
		for (int j = 1; j <= K; j++) {

			for (int k = 1; k <= N; k++) {


				if (item[k][0] > j) {
					memo[j][k] = memo[j][k - 1];
				}
				else memo[j][k] = max(memo[j][k - 1], item[k][1] + memo[j - item[k][0]][k - 1]);

				
			}

		}

		cout << memo[K][N];
	
	
	
	return 0;
}

			